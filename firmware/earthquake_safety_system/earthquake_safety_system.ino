
#include <Wire.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <LiquidCrystal_I2C.h>
#include <math.h>

Adafruit_MPU6050 mpu;
LiquidCrystal_I2C lcd(0x27, 16, 2);

// OUTPUT PINS
const int LED_PIN = 6;
const int BUZZER_PIN = 8;
const int RELAY_PIN = 7;

// Relay activation assumption
const int RELAY_ACTIVE_LEVEL = HIGH;
const int RELAY_INACTIVE_LEVEL = LOW;

// SENSOR CALIBRATION
float offsetX = 0;
float offsetY = 0;
float offsetZ = 0;

const int CALIBRATION_SAMPLES = 200;

// MOVING AVERAGE FILTER
const int FILTER_SIZE = 10;
float samples[FILTER_SIZE] = {0};

int sampleIndex = 0;
int sampleCount = 0;

// SYSTEM SETTINGS
const int WARNING_LEVEL = 5;
const unsigned long WARNING_DELAY = 300;

unsigned long warningStartTime = 0;
bool warningState = false;

// CALIBRATION
void calibrateSensor() {

  float sumX = 0;
  float sumY = 0;
  float sumZ = 0;

  lcd.clear();
  lcd.print("Calibrating...");

  Serial.println("Keep sensor still.");

  for (int i = 0; i < CALIBRATION_SAMPLES; i++) {

    sensors_event_t accel, gyro, temp;
    mpu.getEvent(&accel, &gyro, &temp);

    sumX += accel.acceleration.x;
    sumY += accel.acceleration.y;
    sumZ += accel.acceleration.z;

    delay(10);
  }

  offsetX = sumX / CALIBRATION_SAMPLES;
  offsetY = sumY / CALIBRATION_SAMPLES;
  offsetZ = sumZ / CALIBRATION_SAMPLES;

  Serial.println("Calibration completed.");
}

// MOVING AVERAGE
float applyMovingAverage(float newValue) {

  samples[sampleIndex] = newValue;
  sampleIndex = (sampleIndex + 1) % FILTER_SIZE;

  if (sampleCount < FILTER_SIZE) {
    sampleCount++;
  }

  float sum = 0;

  for (int i = 0; i < sampleCount; i++) {
    sum += samples[i];
  }

  return sum / sampleCount;
}

// VIBRATION LEVEL
int calculateLevel(float acceleration) {

  if (acceleration < 0.20) return 1;
  if (acceleration < 0.40) return 2;
  if (acceleration < 0.60) return 3;
  if (acceleration < 0.80) return 4;
  if (acceleration < 1.00) return 5;
  if (acceleration < 1.20) return 6;
  if (acceleration < 1.40) return 7;
  if (acceleration < 1.60) return 8;
  if (acceleration < 1.80) return 9;
  if (acceleration < 2.00) return 10;
  if (acceleration < 2.20) return 11;

  return 12;
}

// NORMAL / WARNING STATE MACHINE
void updateSystemState(int level) {

  if (level >= WARNING_LEVEL) {

    if (warningStartTime == 0) {
      warningStartTime = millis();
    }

    if (millis() - warningStartTime >= WARNING_DELAY) {
      warningState = true;
    }

  } else {

    warningStartTime = 0;
    warningState = false;
  }
}

// LED, BUZZER AND RELAY CONTROL
void updateOutputs() {

  if (warningState) {

    digitalWrite(LED_PIN, HIGH);
    digitalWrite(BUZZER_PIN, HIGH);
    digitalWrite(RELAY_PIN, RELAY_ACTIVE_LEVEL);

  } else {

    digitalWrite(LED_PIN, LOW);
    digitalWrite(BUZZER_PIN, LOW);
    digitalWrite(RELAY_PIN, RELAY_INACTIVE_LEVEL);
  }
}

// LCD DISPLAY
void updateLCD(int level) {

  lcd.setCursor(0, 0);
  lcd.print("LEVEL: ");
  lcd.print(level);
  lcd.print("   ");

  lcd.setCursor(0, 1);

  if (warningState) {
    lcd.print("STATUS: WARNING ");
  } else {
    lcd.print("STATUS: NORMAL  ");
  }
}

// SETUP
void setup() {

  Serial.begin(9600);
  Wire.begin();

  // Configure outputs
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(RELAY_PIN, OUTPUT);

  // Safe initial output state
  digitalWrite(LED_PIN, LOW);
  digitalWrite(BUZZER_PIN, LOW);
  digitalWrite(RELAY_PIN, RELAY_INACTIVE_LEVEL);

  // LCD initialization
  lcd.init();
  lcd.backlight();
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("EARTHQUAKE");
  lcd.setCursor(0, 1);
  lcd.print("SAFETY SYSTEM");

  delay(1500);

  // MPU6050 initialization
  if (!mpu.begin()) {

    Serial.println("MPU6050 NOT FOUND!");

    lcd.clear();
    lcd.print("SENSOR ERROR!");

    while (1) {
      digitalWrite(LED_PIN, LOW);
      digitalWrite(BUZZER_PIN, LOW);
      digitalWrite(RELAY_PIN, RELAY_INACTIVE_LEVEL);
      delay(100);
    }
  }

  mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
  mpu.setGyroRange(MPU6050_RANGE_500_DEG);
  mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);

  calibrateSensor();

  lcd.clear();
  lcd.print("SYSTEM READY");

  delay(1000);
}

// MAIN LOOP
void loop() {

  sensors_event_t accel, gyro, temp;
  mpu.getEvent(&accel, &gyro, &temp);

  float ax = accel.acceleration.x - offsetX;
  float ay = accel.acceleration.y - offsetY;
  float az = accel.acceleration.z - offsetZ;

  float magnitude = sqrt(
    ax * ax + ay * ay + az * az
  );

  float filtered = applyMovingAverage(magnitude);

  int level = calculateLevel(filtered);

  updateSystemState(level);
  updateOutputs();
  updateLCD(level);

  Serial.print("Acceleration: ");
  Serial.print(filtered);

  Serial.print(" m/s^2 | LEVEL: ");
  Serial.print(level);

  Serial.print(" | STATE: ");

  if (warningState) {
    Serial.println("WARNING");
  } else {
    Serial.println("NORMAL");
  }

  delay(100);
}
