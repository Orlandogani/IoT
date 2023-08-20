void setup()
{
  Serial.print(9600);
  pinMode(7, INPUT);
  pinMode(13, OUTPUT);
}

void loop()
{
  int nilaiTilt = digitalRead(7);
  Serial.print(nilaiTilt);

  if(nilaiTilt == HIGH)
  {
    Serial.println(" Miring");
    digitalWrite(13, HIGH);
  }
  else
  {
    Serial.print(" Tegak");
    digitalWrite(13, LOW);
  }
  delay(200);
}
