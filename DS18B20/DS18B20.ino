#include <OneWire.h>
#include <DallasTemperature.h>
int en1 = 11;
int in1 = 13;
int in2 = 12;

OneWire wiring (A0);
DallasTemperature sensor (&wiring);

void setup ()
{
  pinMode (en1, OUTPUT);
  pinMode (in1, OUTPUT);
  pinMode (in2, OUTPUT);
  sensor.begin();
  Serial.begin(9600);
}
void loop()
{
  sensor.setResolution(9);
  sensor.requestTemperatures();
  float dataSuhu = sensor.getTempCByIndex(0);
  Serial.print("Suhu Terdeteksi: ");
  Serial.println(dataSuhu);
  delay (100);
}
