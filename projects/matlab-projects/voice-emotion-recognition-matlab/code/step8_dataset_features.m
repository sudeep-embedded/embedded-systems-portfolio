clc;
clear;

folders = {'neutral','happy','sad','angry'};
labels  = [1 2 3 4];

X = [];
Y = [];

for f = 1:length(folders)

    folderPath = fullfile('../data', folders{f});
    files = dir(fullfile(folderPath,'*.wav'));

    fprintf('Processing %s (%d files)\n', folders{f}, length(files));

    for i = 1:length(files)

        filePath = fullfile(folderPath, files(i).name);

        % Read audio
        [x, fs] = audioread(filePath);
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

        % MFCC (includes energy → 14 coeffs)
        mf = mfcc(x, fs);

        % Delta & Delta-Delta
        d1 = diff(mf);
        d2 = diff(d1);

        % Fixed-length feature vector (mean statistics)
        feat = [
            mean(mf,1), ...
            mean(d1,1), ...
            mean(d2,1)
        ];

        X = [X; feat];
        Y = [Y; labels(f)];
    end
end

% Save features
if ~exist('../results','dir')
    mkdir('../results');
end

save('../results/features.mat','X','Y');

fprintf('====================================\n');
fprintf('Feature matrix size: %d x %d\n', size(X,1), size(X,2));
fprintf('Label vector size  : %d x %d\n', size(Y,1), size(Y,2));
fprintf('====================================\n');
