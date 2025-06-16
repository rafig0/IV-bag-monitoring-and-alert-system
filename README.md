# 🩺 IV Bag Monitoring and Alert System (ESP32 + Load Cell)

A smart, real-time IV fluid monitoring system using an ESP32 microcontroller and load cell sensor to detect low fluid levels and alert healthcare staff before it’s too late.

## 💡 Project Overview

In hospital settings, monitoring IV fluid levels is critical. Traditional methods rely on nurses manually checking each IV bag, which is time-consuming and prone to human error. This project automates that process by using:

- 📦 A **Strain gauge load cell** to measure fluid weight
- 🧠 An **ESP32** microcontroller for processing
- 🔔 A **buzzer** to alert when the fluid level goes below the set threshold

---

## 🔧 Components Used

| Component              | Quantity | Description |
|------------------------|----------|-------------|
| ESP32 Dev Board        | 1        | Microcontroller to interface with all components|
| Strain gauge Load Cell | 1        | Measures the weight of the IV fluid bag |
| HX711 Amplifier Module | 1        | Converts analog signal from the load cell to digital |
| Buzzer                 | 1        | Auditory Alert for low fluid level |
| Wires + Breadboard     | -        | For connections |
| Power Supply (USB)     | 1        | To power the ESP32 board |
| LCD Display            | 1        | To display the amount of percentage & fluid remaining in the IV bag
---

## ⚙️ How It Works

1. The IV bag is placed on the **load cell** platform. 
2. The **HX711 module** amplifies the analog signal and sends it to the ESP32.
3. The ESP32 calculates the current weight of the IV bag.
4. The LCD display shows the remaining fluid in the IV bag in both milliliters and percentage.
5. If the weight drops below a preset threshold (e.g., 100g), the ESP32 triggers:
   - 🔔 An alert via **buzzer**
   - Optionally: A **cloud-based alert** using Wi-Fi or MQTT (if extended)

---

## 📐 Circuit Diagram

![image](https://github.com/user-attachments/assets/e087284d-0336-4854-a9b9-f0a9c9a08e9c)


