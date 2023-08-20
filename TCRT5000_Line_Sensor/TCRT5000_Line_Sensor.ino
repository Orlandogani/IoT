void setup()
{
  Serial.begin(9600); //Set serial baud rate to 9600 bps
}
void loop()
{
  Serial.println(digitalRead(2)); //Print the value to serial port
  delay(500);
}
