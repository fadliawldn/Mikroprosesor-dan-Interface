void setup() {
  Serial.begin(9600);
}

void loop() {
  int adcValue = analogRead(A0);
  Serial.println(adcValue);
  delay(100);
}