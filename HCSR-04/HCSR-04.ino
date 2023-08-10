#define echoPin 7
#define trigPin 8
long duration,inches,cm; 
void setup() { 
Serial.begin(9600);
pinMode(trigPin,OUTPUT);
pinMode(echoPin,INPUT);
}
void loop() { 
digitalWrite(trigPin,LOW); 
delayMicroseconds(2); 
digitalWrite(trigPin,HIGH); 
delayMicroseconds(5); 
digitalWrite(trigPin,LOW); 
duration = pulseIn(echoPin,HIGH);
inches = microsecondsToInches(duration);
cm = microsecondsToCentimeters(duration); 
Serial.print(cm);
Serial.print("cm");
Serial.println();
delay(500);
}
long microsecondsToInches(long microseconds){
return 
microseconds/74/2;
}
long microsecondsToCentimeters(long microseconds)
{
return 
microseconds/29/2;
}
