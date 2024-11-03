#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10   
#define RST_PIN 9    

MFRC522 rfid(SS_PIN, RST_PIN); 

void setup() {
  Serial.begin(9600); 
  SPI.begin();        
  rfid.PCD_Init();   
  Serial.println("Scan KTP untuk membaca UID...");
}

void loop() {
  
  if (rfid.PICC_IsNewCardPresent()) {
    if (rfid.PICC_ReadCardSerial()) {
     
      Serial.print("UID kartu: ");
      String uidString = "";
      for (byte i = 0; i < rfid.uid.size; i++) {
        uidString += String(rfid.uid.uidByte[i], HEX);
        if (i < rfid.uid.size - 1) {
          uidString += ":";
        }
        Serial.print(rfid.uid.uidByte[i], HEX);
        Serial.print("KELOMPOK KECE");
      }
      Serial.println();
      
     
      if (uidString == "5:8f:49:29:8e:a2:0") { 
        Serial.println("Kartu dikenali!");
      
      } else {
        Serial.println("Kartu Dikenali.");
      }
      
      
      rfid.PICC_HaltA();
    }
  }
}