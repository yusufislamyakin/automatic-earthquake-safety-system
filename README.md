
# Automatic Earthquake Safety System

An Arduino-based vibration detection and automatic warning prototype developed as an Electrical and Electronics Engineering project.

## Project Overview

This project demonstrates a sensor-based vibration monitoring and warning system using an MPU6050 accelerometer and gyroscope sensor with an Arduino Uno.

The system processes motion measurements and evaluates predefined vibration thresholds. When the warning condition is met, visual and audible alerts are activated, along with a relay control output.

The project is an educational prototype and is not intended to predict earthquakes or replace certified earthquake early-warning systems.

## Hardware Components

| Component | Function |
|---|---|
| Arduino Uno | Main microcontroller |
| MPU6050 | Acceleration and angular velocity measurement |
| 16x2 I2C LCD | Vibration level and system status display |
| Buzzer | Audible warning |
| LED | Visual warning |
| Relay Module | Switching control output |

## System Architecture

**Sensor Layer:** MPU6050 measures acceleration and angular velocity.

**Processing Layer:** Arduino Uno performs sensor calibration, signal processing, vibration level calculation, and state evaluation.

**Output Layer:** LCD, LED, buzzer, and relay provide system status and warning responses.

## Technologies

- Arduino IDE
- Embedded C/C++
- MPU6050
- I2C Communication
- Sensor Calibration
- Moving Average Filtering
- State Machine Logic

## Development Status

### Implemented in the prototype

- [x] Arduino Uno integration
- [x] MPU6050 sensor integration
- [x] Sensor baseline calibration
- [x] Vibration level calculation (1–12 experimental scale)
- [x] Moving average filtering
- [x] NORMAL / WARNING state logic
- [x] LCD display software integration
- [x] Buzzer control software
- [x] LED control software
- [x] Relay control software

### Remaining work

- [ ] Validate the updated integrated firmware on physical hardware
- [ ] Verify relay activation logic and switching behavior
- [ ] Calibrate vibration thresholds through controlled experiments
- [ ] Perform systematic hardware tests and document results
- [ ] Develop MATLAB / Simulink simulation
- [ ] Prepare circuit schematics and hardware documentation

## Project Structure

```text
automatic-earthquake-safety-system/
├── docs/
├── firmware/
│   └── earthquake_safety_system/
├── hardware/
├── simulations/
│   ├── LTspice/
│   └── MatlabSimulink/
├── data/
└── README.md
```

## Limitations and Safety

This project is an educational desktop prototype. Its vibration levels are experimental indicators and do not represent official earthquake magnitude or intensity scales.

The updated firmware has not yet been fully validated on the physical prototype. The system is not certified for building protection, real-world earthquake early warning, or safety-critical electrical switching.

## License

This project is licensed under the MIT License.
