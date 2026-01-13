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

% MFCC
mf = mfcc(x, fs);   % default → includes energy

% Delta (1st derivative)
delta1 = diff(mf);

% Delta-Delta (2nd derivative)
delta2 = diff(delta1);

% Display sizes
fprintf('MFCC size        : %d x %d\n', size(mf,1), size(mf,2));
fprintf('Delta size       : %d x %d\n', size(delta1,1), size(delta1,2));
fprintf('Delta-Delta size : %d x %d\n', size(delta2,1), size(delta2,2));

% Plot Delta MFCCs
figure;
imagesc(delta1');
axis xy;
xlabel('Frame Index');
ylabel('Coefficient Index');
title('Delta MFCC Features');
colorbar;
