# Heater-Control-System
Embedded Systems Intern Assignment for upliance.ai

# Heater Control System – Embedded Systems Intern Assignment (upliance.ai)

## Author
Susarla Himavarsha

---

## Project Title
**Heater Control System using DS18B20 Temperature Sensor and State Machine**

---

## Description
This project simulates a basic heater control system using a DS18B20 temperature sensor and two LEDs to indicate heating and overheating states. The system operates on an Arduino UNO board and follows a state machine logic to move between the following states:

- **IDLE:** Temperature is below 30°C  
- **HEATING:** Temperature is between 30°C and 34°C  
- **STABILIZING:** Temperature is between 34°C and 35°C  
- **TARGET_REACHED:** Temperature is exactly 35°C  
- **OVERHEAT:** Temperature exceeds 45°C

---

## Hardware and Tools Used
- Arduino UNO (simulated in Wokwi)
- DS18B20 Temperature Sensor
- Two LEDs (Yellow for heating, Red for overheat)
- 4.7kΩ Pull-up Resistor for DS18B20
- Wokwi Simulator

---

## System Design Highlights
- Real-time temperature monitoring
- State-based LED indication
- Safe shutdown on overheat
- Modular and readable code structure

---

## How to Run the Project

1. Visit the Wokwi Simulation link:  
   🔗 [Wokwi Simulation](https://wokwi.com/projects/438194143997126657)

2. Upload or paste the code into the Arduino IDE inside Wokwi.

3. Observe the Serial Monitor for live temperature updates and state logs.

4. The **Yellow LED** (Pin 6) turns ON when in **HEATING** state.  
   The **Red LED** (Pin 7) turns ON in **OVERHEAT** state.

---

## State Logic

| Temperature Range (°C) | System State     | Heater (Pin 6) | Alert LED (Pin 7) |
|------------------------|------------------|----------------|-------------------|
| < 30                   | IDLE             | OFF            | OFF               |
| 30 - 33.9              | HEATING          | ON             | OFF               |
| 34 - 34.9              | STABILIZING      | OFF            | OFF               |
| 35                     | TARGET_REACHED   | OFF            | OFF               |
| > 45                   | OVERHEAT         | OFF            | ON                |

---


