#define pwm1 10
#define pwm2 11
#define en1 8
#define en2 7

void setup() {
  // put your setup code here, to run once:
  pinMode(pwm1, OUTPUT);
  pinMode(pwm2, OUTPUT);
  pinMode(en1, OUTPUT);
  pinMode(en2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(en1, HIGH);
  digitalWrite(en2, HIGH);
  analogWrite(pwm1, 0);
  analogWrite(pwm2, 125);
  delay(1000);
  analogWrite(pwm1, 125);
  analogWrite(pwm2, 0);
  delay(1000);
}
