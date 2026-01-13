clc;
clear;

% Load trained model
load('../results/svm_model.mat');

% Load test audio
[testSignal, fs] = audioread('C:\Users\sudee\OneDrive\Desktop\steps for mat projects\03-01-02-01-01-02-01.wav');

% Convert to mono
if size(testSignal,2) > 1
    testSignal = mean(testSignal,2);
end

% Preprocessing
testSignal = testSignal - mean(testSignal);
testSignal = testSignal / max(abs(testSignal));

if fs ~= 16000
    testSignal = resample(testSignal,16000,fs);
    fs = 16000;
end

% MFCC
mf = mfcc(testSignal, fs);

% Delta & Delta-Delta
d1 = diff(mf);
d2 = diff(d1);

% Feature vector (same as training)
testFeature = [ ...
    mean(mf,1), ...
    mean(d1,1), ...
    mean(d2,1) ...
];

% Predict emotion
predictedLabel = predict(svmModel, testFeature);

% Label mapping
emotionNames = {'Neutral','Happy','Sad','Angry'};

fprintf('Predicted Emotion: %s\n', emotionNames{predictedLabel});
