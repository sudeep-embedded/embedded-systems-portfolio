clc;
clear;

% Source folder (mixed WAV files)
srcFolder = 'C:\Users\sudee\OneDrive\Desktop\first mat project 1\data\raw';

% Destination folders
dstNeutral = 'C:\Users\sudee\OneDrive\Desktop\first mat project 1\data\neutral';
dstHappy   = 'C:\Users\sudee\OneDrive\Desktop\first mat project 1\data\happy';
dstSad     = 'C:\Users\sudee\OneDrive\Desktop\first mat project 1\data\sad';
dstAngry   = 'C:\Users\sudee\OneDrive\Desktop\first mat project 1\data\angry';

% Create destination folders if they don't exist
if ~exist(dstNeutral,'dir'), mkdir(dstNeutral); end
if ~exist(dstHappy,'dir'),   mkdir(dstHappy);   end
if ~exist(dstSad,'dir'),     mkdir(dstSad);     end
if ~exist(dstAngry,'dir'),   mkdir(dstAngry);   end

% Read all WAV files from raw
files = dir(fullfile(srcFolder,'*.wav'));

fprintf('Total WAV files found in raw: %d\n', length(files));

for i = 1:length(files)

    fname = files(i).name;
    parts = split(fname,'-');

    % Safety check for filename format
    if length(parts) < 3
        continue;
    end

    emotionCode = parts{3};
    srcPath = fullfile(srcFolder, fname);

    switch emotionCode
        case '01'   % Neutral
            copyfile(srcPath, dstNeutral);

        case '03'   % Happy
            copyfile(srcPath, dstHappy);

        case '04'   % Sad
            copyfile(srcPath, dstSad);

        case '05'   % Angry
            copyfile(srcPath, dstAngry);

        otherwise
            % Ignore other emotions (fear, disgust, etc.)
    end
end

disp('Emotion-wise dataset separation completed.');
