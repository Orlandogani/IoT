#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
void setup()
{
  lcd.begin();
  lcd.setCursor(0,0);
  lcd.print("LCD 16x2");
  delay(1000);
}
void loop()
{
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Ketik");
  lcd.setCursor(0,1);
  lcd.print("Disini");
  delay(100);
}
