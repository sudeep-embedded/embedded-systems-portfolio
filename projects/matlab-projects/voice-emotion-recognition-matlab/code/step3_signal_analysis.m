clc;
clear;
close all;

% Load one sample file (change emotion if needed)
filePath = '../data/neutral/';
files = dir(fullfile(filePath,'*.wav'));
[x, fs] = audioread(fullfile(filePath, files(1).name));

if size(x,2) > 1
    x = mean(x,2);
end

t = (0:length(x)-1)/fs;

% Time-domain plot
figure;
plot(t, x);
xlabel('Time (s)');
ylabel('Amplitude');
title('Time Domain Signal');

% FFT
X = fft(x);
N = length(X);
f = (0:N-1)*(fs/N);

figure;
plot(f(1:N/2), abs(X(1:N/2)));
xlabel('Frequency (Hz)');
ylabel('Magnitude');
title('FFT Magnitude Spectrum');

% Spectrogram
figure;
spectrogram(x, hamming(256), 128, 512, fs, 'yaxis');
title('Spectrogram');
