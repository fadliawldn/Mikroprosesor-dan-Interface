#define LM35_PIN A0 // Pin analog untuk sensor LM35

void setup() {
  Serial.begin(9600); // Inisialisasi Serial Monitor
}

void loop() {
  // Baca nilai analog dari LM35
  int sensorValue = analogRead(LM35_PIN);
  
  // Konversi nilai analog ke suhu dalam Celsius
  float voltage = sensorValue * (5.0 / 1023.0); // Konversi ke volt
  float temperature = voltage * 100; // LM35 menghasilkan 10mV per °C

  // Tampilkan hasil di Serial Monitor
  Serial.print("Suhu: ");
  Serial.print(temperature);
  Serial.println(" *C");

  // Tunggu 2 detik sebelum pengukuran berikutnya
  delay(2000);
}