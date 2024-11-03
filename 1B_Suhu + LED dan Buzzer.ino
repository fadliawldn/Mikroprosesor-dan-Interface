#define LM35_PIN A0 // Pin analog untuk sensor LM35
#define LED_PIN 8    // Pin untuk LED
#define BUZZER_PIN 9  // Pin untuk Buzzer

void setup() {
  Serial.begin(9600); // Inisialisasi Serial Monitor
  pinMode(LED_PIN, OUTPUT); // Set pin LED sebagai OUTPUT
  pinMode(BUZZER_PIN, OUTPUT); // Set pin Buzzer sebagai OUTPUT
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

  // Nyalakan LED dan buzzer jika suhu >= 25 derajat
  if (temperature >= 25) {
    digitalWrite(LED_PIN, HIGH); // Nyalakan LED
    digitalWrite(BUZZER_PIN, HIGH); // Nyalakan Buzzer
  } else {
    digitalWrite(LED_PIN, LOW); // Matikan LED
    digitalWrite(BUZZER_PIN, LOW); // Matikan Buzzer
  }

  // Tunggu 2 detik sebelum pengukuran berikutnya
  delay(2000);
}