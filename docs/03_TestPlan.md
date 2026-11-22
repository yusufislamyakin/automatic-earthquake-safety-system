
# System Test and Validation Plan

## 1. Objective

The purpose of this test plan is to evaluate the functionality, reliability, and response behavior of the Automatic Earthquake Safety System.

Testing will be performed progressively during hardware and firmware development.

## 2. Test Environment

The planned test environment includes:

- Arduino Uno
- MPU6050 accelerometer and gyroscope
- Buzzer
- LED
- Relay module
- USB power supply
- Computer with Arduino IDE

## 3. Functional Tests

### Test 1: Sensor Initialization

**Objective:** Verify that the MPU6050 communicates correctly with Arduino Uno.

**Procedure:**
1. Connect the MPU6050 through the I2C interface.
2. Upload the firmware.
3. Check sensor initialization.
4. Observe the communication status.

**Expected Result:** The sensor should initialize successfully.

### Test 2: Sensor Calibration

**Objective:** Evaluate the sensor offset and baseline measurements.

**Procedure:**
1. Place the sensor on a stable surface.
2. Collect measurements while stationary.
3. Calculate the average sensor offset.
4. Record the calibration values.

**Expected Result:** The system should establish a stable reference condition.

### Test 3: Vibration Detection

**Objective:** Evaluate the response to controlled vibrations.

**Procedure:**
1. Place the sensor on a stable surface.
2. Apply controlled mechanical vibrations.
3. Record acceleration measurements.
4. Compare the measurements with detection thresholds.

**Expected Result:** The algorithm should identify qualifying vibration events.

### Test 4: False Alarm Evaluation

**Objective:** Evaluate the effect of normal environmental disturbances.

**Procedure:**
1. Operate the sensor under normal conditions.
2. Record small movements and disturbances.
3. Observe the detection algorithm.
4. Record any unwanted alarm activation.

**Expected Result:** Normal disturbances should not unnecessarily trigger the warning system.

### Test 5: Output Control

**Objective:** Verify the warning output components.

**Procedure:**
1. Generate a simulated warning condition.
2. Observe buzzer activation.
3. Observe LED behavior.
4. Verify relay switching behavior.

**Expected Result:** All outputs should respond according to the configured control logic.

### Test 6: Sensor Communication Failure

**Objective:** Evaluate system behavior when sensor communication is interrupted.

**Procedure:**
1. Start the system.
2. Interrupt the sensor connection under safe test conditions.
3. Observe the communication status.
4. Check the system fault response.

**Expected Result:** The system should identify the sensor fault and enter the defined fault-handling state.

### Test 7: Power Interruption

**Objective:** Evaluate system startup after power interruption.

**Procedure:**
1. Operate the system under normal conditions.
2. Disconnect the power supply.
3. Restore power.
4. Observe initialization and output states.

**Expected Result:** The system should restart safely and initialize its components correctly.

## 4. Performance Measurements

The following parameters will be recorded during testing:

| Parameter | Measurement |
|---|---|
| Sensor sampling rate | Samples per second |
| Acceleration magnitude | g |
| Detection threshold | g |
| Detection response time | ms |
| False alarm count | Number of events |
| Sensor communication status | Pass / Fail |

## 5. Test Results

Actual measurements and test outcomes will be added after experimental validation.

No test result is considered successful until it has been performed and documented.

## 6. Validation Criteria

The system will be evaluated based on:

- Reliable sensor communication.
- Consistent sensor measurements.
- Appropriate vibration detection.
- Reduced false alarm activation.
- Correct warning output behavior.
- Defined fault handling.

## 7. Safety Considerations

All tests will be conducted in a controlled environment.

The relay will initially be tested without connecting it to mains electrical installations or critical equipment.

This prototype is not certified for real-world building safety applications.

## 8. Development Status

This test plan defines the intended verification procedures. Test results will be documented as hardware and firmware development progresses.
