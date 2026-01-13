# Voice Emotion Recognition using MATLAB

## Project Overview
This project implements a **Voice Emotion Recognition (VER)** system using **MATLAB**.  
The goal is to identify the **emotional state of a speaker** from a speech signal.

The system analyzes recorded voice samples, extracts meaningful speech features, and classifies the emotion using a machine learning approach. The project focuses on **signal processing and pattern recognition**, not real-time deployment.

---

## Emotions Considered
- Neutral
- Happy
- Sad
- Angry

---

## How the Project Works (Step-by-Step)

1. **Speech Input Collection**  
   Speech samples are collected from a standard emotional speech dataset (RAVDESS). Each audio file contains a speaker expressing a specific emotion.

2. **Signal Analysis**  
   The speech signal is analyzed in:
   - Time domain (waveform)
   - Frequency domain (FFT)
   - Time–frequency domain (spectrogram)

3. **Preprocessing**  
   Audio signals are standardized by:
   - Resampling
   - Normalizing amplitude
   - Removing unwanted variations

4. **Framing and Windowing**  
   Speech signals are divided into short frames to capture local speech characteristics.

5. **Feature Extraction (MFCC)**  
   Mel Frequency Cepstral Coefficients (MFCCs) are extracted from each frame.  
   These features represent how humans perceive sound and are widely used in speech analysis.

6. **Delta Feature Calculation**  
   Delta MFCC features are computed to capture changes in speech patterns over time.

7. **Feature Dataset Creation**  
   Extracted features are combined into a structured dataset, where each feature vector is associated with its corresponding emotion label.

8. **Machine Learning Classification**  
   A supervised machine learning classifier is trained using the feature dataset to learn emotion-specific patterns.

9. **Emotion Prediction**  
   For a new or unseen speech sample, the trained model predicts the most likely emotion.

---

## Output of the Project
- Emotion label predicted for a speech sample
- Visual plots such as waveform, spectrogram, and MFCCs
- Trained emotion classification model

---

## Applications
- Human–Computer Interaction
- Speech emotion analysis
- Call center sentiment monitoring
- Mental health support systems
- Educational DSP and ML projects

---

## Key Highlights
- Uses real emotional speech dataset
- Combines DSP and machine learning
- Modular MATLAB implementation
- Suitable for academic and portfolio purposes

---

## Limitations
- Works best with clean speech
- Limited number of emotions
- Not implemented for real-time processing

---

## Author
**Sudeep J Elahole**  
B.Tech – Electronics and Communication Engineering  
MATLAB | DSP | Machine Learning
