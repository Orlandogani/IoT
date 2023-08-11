#include <Wire.h>
#include <Adafruit_INA219.h>
Adafruit_INA219 ina219;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while (!Serial) {
    // will pause Zero, Leonardo, etc until serial console opens
    delay(1);
  }
  uint32_t currentFrequency;
  ina219.begin();
  Serial.println("Measuring voltage and current with INA219 ...");
  
}

void loop() {
  // put your main code here, to run repeatedly:
  float current_mA = 0;
  float loadvoltage = 0;
  float power_mW = 0;
  current_mA = ina219.getCurrent_mA();
  power_mW = ina219.getPower_mW();
  loadvoltage = ina219.getBusVoltage_V() + (ina219.getShuntVoltage_mV() / 1000);
  Serial.print("Load Voltage:  "); Serial.print(loadvoltage); Serial.println(" V");
  Serial.print("Current:       "); Serial.print(current_mA); Serial.println(" mA");
  Serial.print("Power:         "); Serial.print(power_mW); Serial.println(" mW");
  Serial.println("");
}
