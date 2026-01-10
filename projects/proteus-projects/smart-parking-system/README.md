# Smart Parking Monitoring System using Arduino

## Overview
This project implements a **Smart Parking Monitoring System** using an Arduino UNO.  
It detects parking slot occupancy, counts vehicle entry/exit, and displays real-time
status on an LCD with LED indicators.

The system is designed to remain inactive when no vehicles are present, improving
power efficiency and reliability.

---

## Hardware Components
- Arduino UNO
- Ultrasonic Sensor × 2 (Slot occupancy detection)
- IR Obstacle Sensor × 2 (Entry and exit counting)
- 16×2 LCD Display
- Red & Green LEDs (Slot status indication)
- Resistors, connecting wires

---

## System Functionality

### 1. Slot Occupancy Detection
Each parking slot is monitored using an ultrasonic sensor.
- Distance < 21 cm → **OCCUPIED**
- Distance ≥ 21 cm → **EMPTY**

Slot status is:
- Displayed on the LCD
- Indicated using LEDs:
  - Red LED → Occupied
  - Green LED → Empty

---

### 2. Entry and Exit Counting
Two IR sensors are placed at:
- Entry gate (IN)
- Exit gate (OUT)

The system maintains a `peopleCount` variable:
- Incremented when IR_IN sensor is triggered
- Decremented when IR_OUT sensor is triggered

Debouncing and latching logic is implemented to avoid false or multiple counts.

---

### 3. Automatic System Activation
The system operates only when vehicles are present:
- `peopleCount > 0` → System ON
- `peopleCount == 0` → System OFF

When OFF:
- LCD display is disabled
- LEDs and ultrasonic triggers are turned off

This reduces unnecessary power usage.

---

## Software Logic
- Ultrasonic sensors measure distance using trigger–echo timing
- IR sensors use interrupt-safe polling with debounce timing
- LCD updates slot status and current count
- Serial output is provided for debugging and monitoring

---

## Pin Configuration

### Ultrasonic Sensors
| Sensor | Trigger | Echo |
|------|--------|------|
| Slot 1 | D2 | D3 |
| Slot 2 | D4 | D5 |

### IR Sensors
| Function | Pin |
|--------|----|
| Entry (IN) | D13 |
| Exit (OUT) | D6 |

### LEDs
| LED | Pin |
|----|----|
| Slot 1 Green | A0 |
| Slot 1 Red | A1 |
| Slot 2 Green | A2 |
| Slot 2 Red | A3 |

---

## Applications
- Smart parking systems
- Vehicle monitoring
- Embedded sensor integration projects
- IoT-based parking solutions (extendable)

---

## Future Improvements
- Add IoT connectivity for remote monitoring
- Store parking data in cloud/database
- Support more parking slots
- Replace polling with interrupts for IR sensors

---

## Author
**Sudeep J Elahole**  
B.Tech ECE | Embedded Systems





**▶️ How to Run the Proteus Simulation**



This project is simulated using Proteus Design Suite with an Arduino UNO microcontroller.



**🔧 Requirements**



Proteus Design Suite 8 or later



Arduino IDE (only required if you want to regenerate the HEX file)



Windows OS



**📂 Project Files Used**



**Proteus project file:**



design/PARKINLOT.pdsprj





**Arduino firmware (HEX):**



firmware/smart\_parking.hex



**🧩 Step 1: Open the Proteus Project**



Open Proteus Design Suite.



Go to File → Open Project.



Navigate to the design/ folder.



Open PARKINLOT.pdsprj.



The complete circuit schematic will load.



**⚙️ Step 2: Load the Arduino HEX File**



Double-click on the Arduino UNO in the schematic.



In the Program File field, browse to:



firmware/smart\_parking.hex





Keep the default clock frequency (Arduino UNO).



Click OK.



**▶️ Step 3: Run the Simulation**



Click the Run (▶) button in Proteus.



The LCD will display a startup message:



SMART PARKING

SYSTEM LOADING





After initialization, the system enters monitoring mode.



**🚗 Step 4: Simulate Vehicle Entry \& Exit**



Entry (IR IN sensor):



Trigger the IR sensor at the entry gate.



Vehicle count (Cnt) increases by 1.



Exit (IR OUT sensor):



Trigger the IR sensor at the exit gate.



Vehicle count decreases by 1.



Debounce logic prevents false or multiple counts.



**🅿️ Step 5: Simulate Parking Slot Occupancy**



Place or move an object in front of the ultrasonic sensors:



Distance < 21 cm → OCCUPIED



Distance ≥ 21 cm → EMPTY



Slot indication:



Red LED → Occupied



Green LED → Empty



The LCD updates slot status in real time.



**⏹️ Step 6: Stop the Simulation**



Click the Stop (■) button in Proteus.



When vehicle count becomes zero, the system automatically turns OFF sensors and display.



**✅ Expected Output**



Accurate slot occupancy detection



Correct vehicle entry/exit count



Real-time LCD updates



Automatic system ON/OFF based on usage



**ℹ️ Notes**



Only one final HEX file is required to run the simulation.



Proteus backup and build files are intentionally excluded from this repository.



Refer to the project report for detailed design and logic explanation.

