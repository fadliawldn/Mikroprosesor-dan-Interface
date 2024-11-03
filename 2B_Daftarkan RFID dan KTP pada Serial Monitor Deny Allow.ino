#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10      // Pin Slave Select
#define RST_PIN 9      // Pin Reset
#define LED_PIN 8      // Pin untuk LED
#define BUZZER_PIN 7   // Pin untuk Buzzer

MFRC522 rfid(SS_PIN, RST_PIN); 

const String validKTPUID = "5:82:16:6f:24:e1:0"; 

void setup() {
  Serial.begin(9600); 
  SPI.begin();       
  rfid.PCD_Init();    
  Serial.println("Scan KTP atau tag RFID...");

  // Inisialisasi pin LED dan Buzzer
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);   // Matikan LED saat mulai
  digitalWrite(BUZZER_PIN, LOW); // Matikan Buzzer saat mulai
}

void loop() {
  // Periksa apakah ada kartu yang terdeteksi
  if (rfid.PICC_IsNewCardPresent()) {
    if (rfid.PICC_ReadCardSerial()) {
      
      String uidString = "";
      for (byte i = 0; i < rfid.uid.size; i++) {
        uidString += String(rfid.uid.uidByte[i], HEX);
        if (i < rfid.uid.size - 1) {
          uidString += ":";
        }
      }

      Serial.print("UID kartu: ");
      Serial.println(uidString);

      // Cek UID kartu
      if (uidString.equalsIgnoreCase(validKTPUID)) {
        Serial.println("ALLOW");
        digitalWrite(LED_PIN, LOW);   // Matikan LED
        digitalWrite(BUZZER_PIN, LOW); // Matikan Buzzer
      } else {
        Serial.println("DENY");
        digitalWrite(LED_PIN, HIGH);   // Nyalakan LED
        digitalWrite(BUZZER_PIN, HIGH); // Nyalakan Buzzer
        delay(2000); // Tunggu 2 detik untuk suara buzzer
        digitalWrite(BUZZER_PIN, LOW);  // Matikan Buzzer setelah 2 detik
        digitalWrite(LED_PIN, LOW);
      }

      // Hentikan komunikasi dengan kartu
      rfid.PICC_HaltA();
    }
  }
}
