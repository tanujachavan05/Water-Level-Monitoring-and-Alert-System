# Smart Water Level Monitoring and Early Warning System

## 📌 Overview
The Smart Water Level Monitoring and Early Warning System is an Arduino Uno–based embedded system designed to monitor water levels in real time and provide early alerts during critical conditions. The system uses an HC-SR04 ultrasonic sensor and a water level sensor to detect changes in water level. When the water level exceeds the predefined threshold, visual, audible, and SMS alerts are generated using LEDs, an active buzzer, and the SIM800L GSM module.

---

## ✨ Features
- Real-time water level monitoring
- Water level detection using ultrasonic and water level sensors
- SMS alerts using SIM800L GSM module
- Visual alerts using LEDs
- Audible alerts using an active buzzer
- Low-cost and easy-to-build hardware solution

---

## 🛠️ Components Used
- Arduino Uno
- HC-SR04 Ultrasonic Sensor
- Water Level Sensor
- SIM800L GSM Module
- Active Buzzer
- LEDs
- 220Ω Resistors
- Breadboard
- Perfboard
- Jumper Wires
- Solid Core Wire
- 3.7V Li-ion Battery

---

## 💻 Software Used
- Arduino IDE
- Embedded C / Arduino Programming

---

## ⚙️ Working
1. The HC-SR04 ultrasonic sensor measures the distance between the sensor and the water surface.
2. The water level sensor detects the presence of water.
3. Arduino Uno processes the sensor data continuously.
4. When the water level reaches the warning threshold:
   - LEDs indicate the water level status.
   - The buzzer sounds an alert.
   - The SIM800L GSM module sends an SMS notification.
5. The system continues monitoring the water level in real time.

---

## 📂 Project Structure
```
Water-Level-Monitoring-and-Alert-System
│── Arduino_Code
│── Images
│── Circuit_Diagram
│── Project_Report.pdf
│── README.md
```

---

## 🚀 Future Improvements
- IoT cloud monitoring
- Mobile application integration
- Water level data logging
- Battery backup optimization

---

## 👩‍💻 Author
**Tanuja Chavan**

Bachelor of Engineering (Information Technology)
