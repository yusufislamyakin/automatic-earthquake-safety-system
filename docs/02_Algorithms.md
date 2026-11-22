
# Vibration Detection Algorithm

## 1. Overview

The system uses an MPU6050 accelerometer and gyroscope sensor to monitor local motion and vibration.

The Arduino Uno processes the sensor measurements and evaluates predefined conditions to determine the system state.

## 2. Sensor Data Acquisition

The MPU6050 provides acceleration measurements along three axes:

- X-axis acceleration
- Y-axis acceleration
- Z-axis acceleration

The total acceleration magnitude can be calculated as:

a_total = sqrt(ax^2 + ay^2 + az^2)

Where:

- ax represents X-axis acceleration.
- ay represents Y-axis acceleration.
- az represents Z-axis acceleration.

The acceleration values must be converted into consistent physical units before processing.

## 3. Calibration

Before normal operation, the system should collect measurements while stationary.

The calibration process estimates the sensor offset and establishes a reference condition.

This helps reduce measurement errors caused by sensor bias and installation orientation.

## 4. Signal Processing

Raw sensor measurements may contain noise and small unwanted variations.

A digital filtering method, such as a moving average filter, can be applied to reduce noise.

The filtered measurements are then used by the detection algorithm.

Gravity compensation should also be considered when evaluating dynamic acceleration.

## 5. Detection Logic

The system evaluates the processed acceleration measurements against experimentally determined thresholds.

A single threshold crossing should not automatically be considered an earthquake event.

The detection logic should consider:

- Acceleration magnitude.
- Duration of the vibration.
- Number of threshold crossings.
- Measurement consistency within a defined time window.

Threshold values and time windows must be determined through experimental testing.

## 6. State Machine

The system uses a state-based control approach.

| State | Condition | Action |
|---|---|---|
| INITIALIZATION | System startup | Initialize sensor |
| NORMAL | No qualifying event | Monitor measurements |
| WARNING | Detection conditions satisfied | Activate warning outputs |
| SENSOR_ERROR | Sensor communication failure | Enter fault handling mode |

The state machine helps prevent uncontrolled output transitions.

## 7. Alarm Management

When the WARNING state is activated:

- Buzzer provides an audible warning.
- LED indicates the warning state.
- Relay output changes according to its configured safety logic.
- LCD displays the system status when integrated.

The alarm reset conditions must be defined and tested.

## 8. Algorithm Flow

1. Initialize Arduino and MPU6050.
2. Check sensor communication.
3. Calibrate sensor measurements.
4. Read acceleration data.
5. Calculate acceleration magnitude.
6. Apply signal filtering.
7. Evaluate vibration conditions.
8. Update the system state.
9. Activate or deactivate warning outputs.
10. Repeat the monitoring cycle.

## 9. Limitations

The algorithm detects local vibration measurements. It does not identify earthquake magnitude, predict earthquakes, or guarantee advance warning.

Its performance must be evaluated through controlled experiments.

## 10. Development Status

This document describes the planned detection algorithm. Actual thresholds, filtering parameters, and response times will be updated after firmware implementation and experimental validation.
