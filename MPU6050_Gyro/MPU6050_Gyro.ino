#include <Wire.h>
#include <MPU6050.h>
MPU6050 mpu;
float accelX_mss, accelY_mss, accelZ_mss;
float gyroX_deg, gyroY_deg, gyroZ_deg;
const int MPU_ADDR = 0x68;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Wire.begin();
  Wire.beginTransmission(MPU_ADDR);
  Wire.write(0x6B);   // PWR_MGMT_1 register
  Wire.write(0);      // Wake up the MPU-6050 (0 = out of sleep mode)
  Wire.endTransmission(true);
}

void loop() {
  // put your main code here, to run repeatedly:
  int16_t accelerometerX, accelerometerY, accelerometerZ;
  int16_t gyroX, gyroY, gyroZ;

  Wire.beginTransmission(MPU_ADDR);
  Wire.write(0x3B);  // Starting register of the accelerometer data
  Wire.endTransmission(false);
  Wire.requestFrom(MPU_ADDR, 14, true);

  accelerometerX = Wire.read() << 8 | Wire.read();
  accelerometerY = Wire.read() << 8 | Wire.read();
  accelerometerZ = Wire.read() << 8 | Wire.read();

  gyroX = Wire.read() << 8 | Wire.read();
  gyroY = Wire.read() << 8 | Wire.read();
  gyroZ = Wire.read() << 8 | Wire.read();

  accelX_mss = accelerometerX / 16384.0;  // Convert raw values to meters per second squared
  accelY_mss = accelerometerY / 16384.0;
  accelZ_mss = accelerometerZ / 16384.0;

  gyroX_deg = gyroX / 131.0;  // Convert raw values to degrees per second
  gyroY_deg = gyroY / 131.0;
  gyroZ_deg = gyroZ / 131.0;

  Serial.print("Acceleration (m/s^2): ");
  Serial.print("X = ");
  Serial.print(accelX_mss);
  Serial.print(", Y = ");
  Serial.print(accelY_mss);
  Serial.print(", Z = ");
  Serial.println(accelZ_mss);

  Serial.print("Angular Velocity (deg/s): ");
  Serial.print("X = ");
  Serial.print(gyroX_deg);
  Serial.print(", Y = ");

  Serial.print(gyroY_deg);
  Serial.print(", Z = ");
  Serial.println(gyroZ_deg);
}
