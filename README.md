
# Automatic Earthquake Safety System

An Arduino-based earthquake detection and automatic safety response prototype developed as an Electrical and Electronics Engineering project.

## Project Overview

This project aims to detect sudden ground vibrations using an MPU6050 accelerometer and gyroscope sensor. An Arduino Uno processes the sensor data and activates warning outputs when predefined vibration conditions are met.

The system is designed as an educational prototype to demonstrate sensor-based monitoring, embedded programming, and automatic response mechanisms.

## Hardware Components

| Component | Function |
|---|---|
| Arduino Uno | Main control unit |
| MPU6050 | Acceleration and angular velocity measurement |
| Buzzer | Audible warning |
| Relay Module | Switching control output |
| LED | Visual warning |
| 16x2 I2C LCD | System status display (planned) |

## System Architecture

**Sensor Layer:** MPU6050 collects motion data.

**Processing Layer:** Arduino Uno processes sensor measurements and evaluates detection conditions.

**Output Layer:** Buzzer, LED, and relay provide warning and control outputs.

## Technologies

- Arduino IDE
- Embedded C/C++
- MPU6050 Sensor
- MATLAB / Simulink (planned)
- LTspice (planned)

## Development Status

This project is currently under development.

- [ ] MPU6050 sensor integration
- [ ] Sensor calibration
- [ ] Vibration detection algorithm
- [ ] Signal filtering
- [ ] Buzzer and LED control
- [ ] Relay control and fail-safe logic
- [ ] LCD integration
- [ ] MATLAB / Simulink simulation
- [ ] Hardware testing and validation

## Project Structure

```text
automatic-earthquake-safety-system/
├── docs/
├── firmware/
├── hardware/
├── simulations/
├── data/
└── README.md
```

## Important Note

This project is an educational prototype and is not certified for real-world earthquake early warning or building safety applications.

## License

This project is licensed under the MIT License.
