clc;
clear;
close all;

% Load one sample file
filePath = '../data/neutral/';
files = dir(fullfile(filePath,'*.wav'));
[x, fs] = audioread(fullfile(filePath, files(1).name));

% Convert to mono if stereo
if size(x,2) > 1
    x = mean(x,2);
end

% DC offset removal
x = x - mean(x);

% Normalization
x = x / max(abs(x));

% Resample to 16 kHz if needed
if fs ~= 16000
    x = resample(x,16000,fs);
    fs = 16000;
end

% Time vector
t = (0:length(x)-1)/fs;

% Plot preprocessed signal
figure;
plot(t,x);
xlabel('Time (s)');
ylabel('Amplitude');
title('Preprocessed Speech Signal');
