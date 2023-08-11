int prox = 10;
int value;
void setup() {
  // put your setup code here, to run once:
  Serial.begin (115200);
  pinMode(prox,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  value = digitalRead(prox);
  Serial.print(value);
}
