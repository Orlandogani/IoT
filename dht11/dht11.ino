#include "DHT.h"
#define DHTPIN 13
#define ldr A0
#define DHTTYPE DHT11
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
DHT dht(DHTPIN, DHTTYPE);
void setup(){
  Serial.begin(9600);
  lcd.begin();
//  lcd.init();
//  lcd.backlight();
  dht.begin();
  pinMode(ldr, INPUT);
}
void loop()
{ 
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float nilaildr = analogRead(ldr);
  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("  Temperature: "));
  Serial.print(t);
  Serial.print(F("°C "));
  Serial.print("  Light: ");
  Serial.print(nilaildr);
  Serial.print("\n");
  lcd.setCursor(0,0);
  lcd.print("TEMPERATURE : ");
  lcd.print(t);
  lcd.setCursor(0,1);
  lcd.print("LIGHT : ");
  lcd.print(nilaildr);
  delay(100);
}
