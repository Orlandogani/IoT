#define ldr A0
float lux = 0.00,ADC_value=0.0048828125;


void setup(){
  Serial.begin(9600);
  pinMode(ldr, INPUT);
}
void loop()
{ 
  float ldrValue = analogRead(ldr);

  //convert flux
  int lux = (250.000000/(ADC_value*ldrValue))-50.000000;
  Serial.print("LIGHT : ");
  Serial.print(lux);
  delay(1000);
}
