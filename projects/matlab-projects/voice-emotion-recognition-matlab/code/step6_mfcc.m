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

% MFCC extraction
coeffs = mfcc(x, fs, 'NumCoeffs', 13);

% Display size
fprintf('MFCC matrix size: %d x %d\n', size(coeffs,1), size(coeffs,2));

% Plot MFCCs
figure;
imagesc(coeffs');
axis xy;
xlabel('Frame Index');
ylabel('MFCC Coefficient Index');
title('MFCC Coefficients');
colorbar;
