void setup() {
  Serial.begin(9600);
}

void loop() {
  int adcValue = analogRead(A0);
  float voltage = (adcValue * 5.0) / 1023.0;
  Serial.print("ADC Value: ");
  Serial.print(adcValue);
  Serial.print(" | Voltage: ");
  Serial.println(voltage);
  delay(100);
}
