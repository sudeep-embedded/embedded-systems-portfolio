📄 README.md
How the System Works (Refined)
Step-by-Step Operation

Open the Proteus project and load the HEX file into the Arduino UNO.

Before running the simulation, configure the Bluetooth module by selecting a COM port (e.g., COM3).

On the laptop, open Bluetooth settings → Advanced settings → COM Ports.

Add an incoming COM port and ensure it matches the COM port selected in Proteus.

Start the Proteus simulation.

Install BT Display app on your mobile phone : https://apkpure.com/bt-display/com.sumanskd47.BT_Display

Open the app, click Scan, and connect to the laptop’s Bluetooth device.

Enter or speak a command and press Send Text.

The Arduino receives the command via serial communication and controls the relays accordingly.

Important Notes

COM port number must be the same in Proteus Bluetooth module and laptop Bluetooth settings.

Commands are processed only after clicking Send Text.

Communication is purely serial-based via Bluetooth.
