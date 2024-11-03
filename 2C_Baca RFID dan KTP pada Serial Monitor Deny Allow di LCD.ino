#include <SPI.h>
#include <MFRC522.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define SS_PIN 10   
#define RST_PIN 9   
#define LED_PIN 8    
#define BUZZER_PIN 7  

MFRC522 rfid(SS_PIN, RST_PIN);
LiquidCrystal_I2C lcd(0x27, 16, 2); 


const String validKTPUID = "5:8f:49:29:8e:a2:0"; 

void setup() {
  Serial.begin(9600);
  SPI.begin();       
  rfid.PCD_Init();    
  lcd.begin(1,5);      
  lcd.backlight();    
  pinMode(LED_PIN, OUTPUT); 
  pinMode(BUZZER_PIN, OUTPUT); 
  Serial.println("Scan KTP atau tag RFID...");
}

void loop() {

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

      
      if (uidString.equalsIgnoreCase(validKTPUID)) {
        Serial.println("ALLOW");
        lcd.clear();
        lcd.print("ALLOW");
        digitalWrite(LED_PIN, LOW); 
        digitalWrite(BUZZER_PIN, LOW); 
      } else {
        Serial.println("DENY");
        lcd.clear();
        lcd.print("DENY");
        digitalWrite(LED_PIN, HIGH); 
        digitalWrite(BUZZER_PIN, HIGH); 
      }

   
      delay(2000);
      
      
      digitalWrite(LED_PIN, LOW);
      digitalWrite(BUZZER_PIN, LOW);

    
     
    }
  }
}