#include <Servo.h>

const int servoPin = 9;
Servo myServo;

void setup() {
  myServo.attach(servoPin);
}

void loop() {
  int adcValue = analogRead(A0);
  int angle = map(adcValue, 0, 1023, 0, 180);
  myServo.write(angle);
  delay(100);
}