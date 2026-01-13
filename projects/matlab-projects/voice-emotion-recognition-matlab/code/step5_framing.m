clc;
clear;
close all;

% Load one sample file
filePath = '../data/neutral/';
files = dir(fullfile(filePath,'*.wav'));
[x, fs] = audioread(fullfile(filePath, files(1).name));

% Convert to mono
if size(x,2) > 1
    x = mean(x,2);
end

% Preprocessing
x = x - mean(x);
x = x / max(abs(x));

if fs ~= 16000
    x = resample(x,16000,fs);
    fs = 16000;
end

% Framing parameters
frameLength = round(0.025 * fs);   % 25 ms → 400 samples
frameShift  = round(0.010 * fs);   % 10 ms → 160 samples
window = hamming(frameLength);

% Number of frames
numFrames = floor((length(x) - frameLength) / frameShift) + 1;

frames = zeros(frameLength, numFrames);

% Frame extraction
for k = 1:numFrames
    startIdx = (k-1)*frameShift + 1;
    frames(:,k) = x(startIdx:startIdx+frameLength-1) .* window;
end

% Display information
fprintf('Frame length (samples): %d\n', frameLength);
fprintf('Frame shift  (samples): %d\n', frameShift);
fprintf('Number of frames      : %d\n', numFrames);

% Plot first frame
figure;
plot(frames(:,1));
xlabel('Samples');
ylabel('Amplitude');
title('First Speech Frame (Windowed)');
