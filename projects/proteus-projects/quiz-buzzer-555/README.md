# Quiz Buzzer Circuit Using 555 Timer (Proteus Simulation)

## Project Overview
This project implements a **quiz buzzer system** using multiple **555 timer ICs**.  
The circuit detects the **first button pressed** among participants and locks out all other inputs. The entire logic is hardware-based and does not use any microcontroller or software.

The circuit is designed and tested using **Proteus Design Suite**.

---

## Components Used
- 555 Timer ICs
- Push Buttons
- Diodes
- Resistors
- LEDs
- DC Power Supply

---

## How to Simulate the Circuit (Step by Step)

### Step 1: Open the Proteus Project
1. Launch **Proteus Design Suite**.
2. Go to **File → Open Project**.
3. Open the project file located in:
4. The complete quiz buzzer schematic will appear on the screen.

---

### Step 2: Verify Initial Conditions
- Ensure all **push buttons are released**
- All **LEDs should be OFF**
- No output should be active at the beginning

This represents the **idle state** of the system.

---

### Step 3: Run the Simulation
1. Click the **Run (▶)** button in Proteus.
2. The simulation starts and the circuit becomes active.

---

### Step 4: Simulate a Participant Response
1. Click **any one push button** (representing a participant).
2. Observe:
- The corresponding **LED turns ON**
- The selected 555 timer output goes HIGH

This indicates the **first valid response**.

---

### Step 5: Verify Lockout Operation
1. After one LED is ON, press the **other push buttons**.
2. Observe:
- No other LEDs turn ON
- Other timer circuits remain disabled

This confirms that the circuit correctly **locks out all other participants**.

---

### Step 6: Reset the Circuit
1. Stop the simulation using the **Stop (■)** button.
2. Restart the simulation using **Run (▶)**.
3. The system returns to its initial state, ready for the next round.

---

## Expected Behavior

| Condition | Result |
|--------|--------|
| No button pressed | All LEDs OFF |
| First button pressed | Corresponding LED ON |
| Other buttons pressed | No response |
| Simulation restarted | System reset |

---

## Notes
- Only one participant can win per round
- The first button press is always given priority
- Logic is implemented purely using hardware
- No programming or firmware is required

---

## Applications
- Quiz competitions
- Classroom response systems
- Game shows
- Educational electronics projects

---

## Author
**Sudeep J Elahole**  
B.Tech Electronics and Communication Engineering  
Embedded Systems & Electronics Design
