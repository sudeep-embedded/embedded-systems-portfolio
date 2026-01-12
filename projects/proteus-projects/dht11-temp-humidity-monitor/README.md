# DHT11 Temperature & Humidity Monitoring System (Arduino)

## Project Overview
This project monitors **temperature and humidity** using a **DHT11 sensor** and displays the values on a **16×2 LCD**.  
Based on the temperature value, an **LED indicator** is automatically controlled to show alert conditions.

The project is designed and simulated using **Proteus Design Suite**.

---

## How the System Works

1. The DHT11 sensor continuously measures:
   - Temperature (°C)
   - Humidity (%)

2. Arduino reads the sensor data and displays it on the LCD:
   - First line → Temperature
   - Second line → Humidity

3. Arduino compares the temperature value with a predefined threshold.

---

## LED Working Condition (IMPORTANT)

### 🔹 Condition 1: Temperature ≤ 25°C
- LED: **OFF**
- LCD: Displays temperature and humidity normally

### 🔹 Condition 2: Temperature > 25°C
- LED: **ON**
- LCD: Displays updated temperature and humidity

The LED acts as a **visual alert indicator** when the temperature exceeds the safe limit.

---

## Control Logic Summary

| Temperature | LED Status |
|------------|------------|
| ≤ 25°C | OFF |
| > 25°C | ON |

---

## Components Used
- Arduino UNO
- DHT11 Temperature & Humidity Sensor
- 16×2 LCD Display
- LED
- Potentiometer (LCD contrast control)

---

## Notes
- Temperature threshold is fixed at **25°C**
- Threshold value can be modified in the Arduino code
- System operates continuously in real time

---

## Author
**Sudeep J Elahole**  
B.Tech – Electronics and Communication Engineering  
Embedded Systems
