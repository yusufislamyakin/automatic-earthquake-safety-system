
# System Architecture

## 1. Overview

The Automatic Earthquake Safety System is an Arduino-based vibration detection and safety response prototype.

The system uses an MPU6050 sensor to measure acceleration and angular velocity. The Arduino Uno processes the collected measurements and evaluates vibration conditions to determine whether a warning should be generated.

## 2. System Architecture

The system consists of four main layers.

### 2.1 Sensor Layer

**MPU6050 Accelerometer and Gyroscope**

- Measures acceleration along X, Y, and Z axes.
- Measures angular velocity along three axes.
- Sends measurement data to Arduino Uno through the I2C communication interface.

### 2.2 Processing Layer

**Arduino Uno**

- Reads sensor measurements.
- Processes acceleration data.
- Applies calibration and signal filtering.
- Evaluates predefined detection thresholds.
- Determines the current system state.
- Controls output components.

### 2.3 Output Layer

**Buzzer**
- Provides an audible warning when a vibration event is detected.

**LED**
- Provides a visual indication of the system status.

**Relay Module**
- Provides a switching output when the configured warning condition is met.
- Its behavior must be designed and tested for safe operation.

**16x2 I2C LCD (Planned)**
- Displays system status.
- Displays vibration measurements and warning messages.

### 2.4 Power and Communication

- Arduino Uno acts as the central controller.
- MPU6050 communicates through I2C.
- The output modules are controlled through digital pins.
- Appropriate power supply and electrical protection must be considered.

## 3. Data Flow

The expected system operation follows these steps:

1. MPU6050 collects motion measurements.
2. Sensor measurements are transmitted to Arduino Uno.
3. Arduino processes and filters the measurements.
4. Detection logic evaluates the vibration conditions.
5. The system determines its operating state.
6. Warning outputs are activated when the configured conditions are satisfied.
7. The system monitors subsequent measurements and updates its state.

## 4. Operating States

The system is designed around the following states:

| State | Description |
|---|---|
| INITIALIZATION | System starts and initializes the sensor |
| NORMAL | No qualifying vibration event detected |
| WARNING | Vibration conditions require an alert |
| SENSOR_ERROR | Sensor communication or initialization failure |

## 5. Fault Handling and Safety

The following conditions must be considered during development:

- Sensor communication failure.
- Invalid or unavailable measurements.
- Power interruption and system restart.
- Unexpected relay activation.
- False vibration detection.

The system should enter a defined fault state when sensor measurements become unavailable.

Relay behavior during startup and sensor failure must be explicitly defined and verified through testing.

## 6. System Limitations

This prototype detects local motion and vibration. It does not predict earthquakes or provide an earthquake early warning service.

It is intended for educational and experimental purposes, not as a certified building safety system.

## 7. Development Status

The architecture represents the intended system design. Hardware integration, firmware implementation, and experimental validation are being developed progressively.
