clc;
clear;
close all;

% Load features
load('../results/features.mat');   % X, Y

fprintf('Feature matrix size: %d x %d\n', size(X,1), size(X,2));
fprintf('Label vector size  : %d x %d\n', size(Y,1), size(Y,2));

% Safety check
if isempty(X) || isempty(Y)
    error('Feature matrix or labels are empty. Re-run step8_dataset_features.');
end

% Train-test split (80–20)
cv = cvpartition(Y,'HoldOut',0.2);

Xtrain = X(training(cv),:);
Ytrain = Y(training(cv));
Xtest  = X(test(cv),:);
Ytest  = Y(test(cv));

fprintf('Training samples: %d\n', size(Xtrain,1));
fprintf('Testing samples : %d\n', size(Xtest,1));

% -------- MULTICLASS SVM (CORRECT WAY) --------
t = templateSVM( ...
    'KernelFunction','rbf', ...
    'Standardize',true);

svmModel = fitcecoc(Xtrain, Ytrain, ...
    'Learners', t);

% Prediction
Ypred = predict(svmModel, Xtest);

% Accuracy
accuracy = mean(Ypred == Ytest) * 100;
fprintf('Classification Accuracy: %.2f %%\n', accuracy);

% Confusion Matrix
figure;
confusionchart(Ytest, Ypred);
title('Speech Emotion Recognition – Confusion Matrix');

% Save model
save('../results/svm_model.mat','svmModel');
