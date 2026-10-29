# Automated 4-Channel Plant Irrigation System

An automated, smart irrigation system built on the Arduino platform that independently monitors the soil moisture levels of up to four separate plants and triggers individual water pumps when the moisture drops below a customizable threshold.

This project features a highly optimized, array-based codebase designed for easy scaling, clean logic execution, and power efficiency.

## 🛠️ System Specifications

* **Microcontroller:** Arduino Uno R3
* **System Voltage (V):** 5.0 V DC
* **Peak System Current (I):** ~2.0 A (Allows overhead for 4 pumps running concurrently)
* **Calibration Limits:** 
  * `0` (Fully Dry baseline)
  * `539` (Fully Wet baseline)

---

## 📊 Individual Plant Configurations

Each channel is configured with custom moisture thresholds to match different plant species, you can modify this to your own configuration:

| Channel | Physical Pins (Sensor / Motor) | Target Threshold | Ideal Plant Type Examples |
| :--- | :--- | :--- | :--- |
| **Plant 1** | Analog `A0` / Digital `13` | `< 30%` | Cacti, Succulents, Jade |
| **Plant 2** | Analog `A1` / Digital `12` | `< 45%` | Monstera, Pothos, Philodendron |
| **Plant 3** | Analog `A2` / Digital `11` | `< 45%` | Ficus, Schefflera, Peperomia |
| **Plant 4** | Analog `A3` / Digital `10` | `< 60%` | Ferns, Calatheas, Peace Lilies |

---

## ⚡ Bill of Materials (BOM)

To build this project physically on a workbench, the following components are required:

| Qty | Component Description | Purpose |
| :--- | :--- | :--- |
| 1 | Arduino Uno R3 (or compatible) | Main controller / Brain |
| 4 | Analog Soil Moisture Sensors | Measuring soil resistance / moisture |
| 4 | 5V Mini Submersible Water Pumps | Pumping water to individual plants |
| 4 | NPN Transistors (e.g., PN2222 or TIP120) | Acting as low-side ground switches for the motors |
| 4 | 220Ω Resistors | Protecting the Arduino digital output pins |
| 4 | 1N4007 Flyback Diodes | **Critical:** Absorbs inductive voltage spikes from pumps |
| 1 | 5V 2A DC Mains Wall Adapter | The real-world "Super Potato" power source |

---

## 🔌 Circuit Blueprint & Schematics

![Tinkercad Circuit Schematic](hardware/schematic_.png)
