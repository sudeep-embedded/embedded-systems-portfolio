Real-Time Adaptive Noise Cancellation (Dual Mic) – MATLAB
What it is

A real-time Adaptive Noise Cancellation (ANC) system built in MATLAB using two microphones and the NLMS adaptive filter to reduce background noise from live speech.

How it works (quick)

Laptop mic → speech + noise (primary signal)

Phone mic (WO Mic) → reference noise

NLMS adaptive filter → learns noise path

Output → noise-reduced speech (headphones)

Architecture: Feedforward two-microphone ANC

Why it matters

Works in real time (not offline files)

Uses correct ANC theory (two microphones)

Demonstrates adaptive DSP, not static filtering

Tools Used

MATLAB (R2023a)

Audio Toolbox

DSP System Toolbox

WO Mic (phone as reference mic)

How to Run

Connect phone via WO Mic (USB)

Plug in headphones

Run:

ANC_DualMic_Full.m


Choose:

1 → Live ANC demo (listen)

2 → Analysis mode (plots)

Results

Background noise reduced in real time

Speech remains clear

Energy and FFT plots confirm noise attenuation

Limitations

Cancels only correlated noise

MATLAB version not embedded-optimized

Minor clock drift between mics possible

Author

Sudeep J Elahole
B.Tech – Electronics & Communication Engineering
Embedded Systems & Signal Processing