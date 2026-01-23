%% REAL-TIME ADAPTIVE NOISE CANCELLATION (DUAL MIC)
% Modes:
% 1 - Live ANC Demo (Listen)
% 2 - Analysis Mode (Capture + Plots)

clc;
clear;

%% ================= USER MODE SELECTION =================
disp('========================================');
disp(' Real-Time Adaptive Noise Cancellation ');
disp('========================================');
disp('1. Live ANC Demo (Listen)');
disp('2. Analysis Mode (Capture + Plots)');
mode = input('Select mode (1 or 2): ');

if ~(mode == 1 || mode == 2)
    error('Invalid mode selected');
end

%% ================= PARAMETERS =================
frameLength  = 256;
filterLength = 64;     % reduced for cleaner output
mu           = 0.15;   % reduced for stability

%% ================= AUDIO DEVICES =================
primaryMic = audioDeviceReader( ...
    'Device', 'Microphone Array (Realtek(R) Audio)', ...
    'SamplesPerFrame', frameLength);

refMic = audioDeviceReader( ...
    'Device', 'Microphone (WO Mic Device)', ...
    'SamplesPerFrame', frameLength);

speaker = audioDeviceWriter;

ancFilter = dsp.LMSFilter( ...
    'Length', filterLength, ...
    'Method', 'Normalized LMS', ...
    'StepSize', mu);

%% ================= PRIME BUFFERS =================
for k = 1:20
    primaryMic();
    refMic();
end

%% ================= MODE 1 : LIVE ANC =================
if mode == 1
    disp('----------------------------------------');
    disp(' LIVE ANC RUNNING ');
    disp(' Press Ctrl + C to stop ');
    disp('----------------------------------------');

    while true
        x = primaryMic();   % speech + noise
        n = refMic();       % reference noise

        [~, e] = ancFilter(n, x);

        % -------- OUTPUT CLEANUP --------
        e = filter([1 1 1]/3, 1, e);                  % smooth hiss
       e = max(min(e, 0.5), -0.5);         % normalize
        % --------------------------------

        speaker(e);         % play cleaned signal
    end
end

%% ================= MODE 2 : ANALYSIS =================
if mode == 2
    numFrames = 200;   % ~3–4 seconds capture

    x_all = [];
    e_all = [];

    disp('----------------------------------------');
    disp(' ANALYSIS MODE: CAPTURING DATA ');
    disp('----------------------------------------');

    for k = 1:numFrames
        x = primaryMic();
        n = refMic();

        [~, e] = ancFilter(n, x);

        % -------- SAME CLEANUP AS LIVE MODE --------
        e = filter([1 1 1]/3, 1, e);
        e = 0.8 * e / (max(abs(e)) + 1e-6);
        % -------------------------------------------

        x_all = [x_all; x];
        e_all = [e_all; e];
    end

    release(primaryMic);
    release(refMic);

    %% ================= TIME DOMAIN PLOTS =================
    figure;
    subplot(2,1,1)
    plot(x_all)
    title('Primary Signal (Speech + Noise)')
    xlabel('Samples')
    ylabel('Amplitude')
    grid on

    subplot(2,1,2)
    plot(e_all)
    title('ANC Output (Noise Reduced)')
    xlabel('Samples')
    ylabel('Amplitude')
    grid on

    %% ================= FREQUENCY DOMAIN =================
    N = length(x_all);
    X = abs(fft(x_all));
    E = abs(fft(e_all));
    f = (0:N-1)/N;

    figure;
    plot(f, 20*log10(X/max(X)), 'r')
    hold on
    plot(f, 20*log10(E/max(E)), 'b')
    legend('Before ANC', 'After ANC')
    xlabel('Normalized Frequency')
    ylabel('Magnitude (dB)')
    title('Frequency Spectrum Comparison')
    grid on

    %% ================= ENERGY REDUCTION =================
    frameEnergyIn  = reshape(x_all.^2, frameLength, []);
    frameEnergyOut = reshape(e_all.^2, frameLength, []);

    Ein  = sum(frameEnergyIn);
    Eout = sum(frameEnergyOut);

    figure;
    plot(10*log10(Ein), 'r')
    hold on
    plot(10*log10(Eout), 'b')
    legend('Input Energy', 'Output Energy')
    xlabel('Frame Index')
    ylabel('Energy (dB)')
    title('Frame-wise Energy Reduction')
    grid on

    disp('----------------------------------------');
    disp(' ANALYSIS COMPLETE ');
    disp('----------------------------------------');
end
