
# Hardware Design and Components

## 1. Overview

This document describes the hardware components and electrical connections planned for the Automatic Earthquake Safety System.

The Arduino Uno acts as the central processing unit and communicates with the MPU6050 sensor through the I2C interface.

## 2. Hardware Components

| Component | Quantity | Function |
|---|---:|---|
| Arduino Uno | 1 | Main controller |
| MPU6050 | 1 | Motion and acceleration sensing |
| Buzzer | 1 | Audible warning |
| LED | 1 | Visual warning |
| Relay Module | 1 | Switching output |
| 16x2 I2C LCD | 1 | Status display |
| Jumper Wires | As needed | Electrical connections |
| Breadboard | 1 | Prototype assembly |

## 3. Arduino Pin Configuration

The following pin assignments are proposed for the prototype.

| Component | Arduino Pin | Function |
|---|---|---|
| MPU6050 SDA | A4 | I2C Data |
| MPU6050 SCL | A5 | I2C Clock |
| LCD SDA | A4 | I2C Data |
| LCD SCL | A5 | I2C Clock |
| Buzzer | D8 | Digital Output |
| LED | D6 | Digital Output |
| Relay IN | D7 | Digital Output |

The MPU6050 and LCD share the I2C communication bus. Their I2C addresses must be checked to avoid address conflicts.

## 4. Sensor Connections

### MPU6050

| MPU6050 Pin | Arduino Uno |
|---|---|
| VCC | According to module specifications |
| GND | GND |
| SDA | A4 |
| SCL | A5 |

The MPU6050 module supply voltage and I2C logic-level requirements must be verified before powering the circuit.

A suitable logic-level interface should be used if required by the sensor module.

## 5. Output Connections

### Buzzer

- Positive terminal: Arduino D8 (through a suitable driver if required).
- Negative terminal: GND.

### LED

- Anode: Arduino D6 through a current-limiting resistor.
- Cathode: GND.

### Relay Module

- IN: Arduino D7.
- VCC: According to module specifications.
- GND: Common ground.

The relay will initially be tested without connecting mains voltage or critical equipment.

### LCD Display

- SDA: Arduino A4.
- SCL: Arduino A5.
- Power connections: According to LCD module specifications.

## 6. Power Requirements

The prototype requires a stable power supply.

The following conditions must be considered:

- Verify operating voltage requirements of every module.
- Avoid exceeding Arduino output pin current limits.
- Use suitable driver circuits for loads requiring more current.
- Check common ground requirements.
- Verify relay module isolation and electrical ratings.

## 7. Hardware Development Status

The component list and pin assignments represent the proposed prototype configuration.

Actual wiring, electrical compatibility, and component behavior must be verified during hardware assembly.

## 8. Safety Notes

This is an educational prototype.

No direct connection to building electrical installations, gas systems, or critical safety equipment is intended.

All initial relay tests must be performed using low-voltage loads in a controlled environment.
