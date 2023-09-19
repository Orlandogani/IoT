#include <DHT.h>
#define DHTPIN A5
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

void setup(){
  Serial.begin(9600);
  dht.begin();
}
void loop()
{ 
  float humi = dht.readHumidity();
  float temp = dht.readTemperature();
  Serial.print("Humidity: ");
  Serial.print(humi);
  Serial.print("  Temperature: ");
  Serial.print(temp);
  delay(1000);
}
