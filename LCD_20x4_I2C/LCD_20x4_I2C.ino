#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 20,4);
void setup() {
  // put your setup code here, to run once:
  lcd.begin();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("LCD 20x4");
  delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.setCursor(0, 0);
  lcd.print("Ketik ");
  lcd.setCursor(0, 1);
  lcd.print("Disini");
}
