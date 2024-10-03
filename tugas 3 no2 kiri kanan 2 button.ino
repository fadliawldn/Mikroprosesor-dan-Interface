const int button1 = 5;
const int button2 = 6;
const int led1 = 4;
const int led2 = 3;
const int led3 = 2;

void setup() {
  // 
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  
  // 
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
}

void loop() {
  // Jika tombol ditekan
  if (digitalRead(button1) == HIGH) {
    
    // Menyalakan LED 1
    digitalWrite(led1, HIGH);
    delay(700); // 
    digitalWrite(led1, LOW); //
    
    // Menyalakan LED 2
    digitalWrite(led2, HIGH);
    delay(700); // 
    digitalWrite(led2, LOW); // 
    
    // Menyalakan LED 3
    digitalWrite(led3, HIGH);
    delay(700); // 
    digitalWrite(led3, LOW); // 
  }

  if (digitalRead(button2) == HIGH) {
    // Menyalakan LED 1
    digitalWrite(led3, HIGH);
    delay(700); // 
    digitalWrite(led3, LOW); //
    
    // Menyalakan LED 2
    digitalWrite(led2, HIGH);
    delay(700); // 
    digitalWrite(led2, LOW); // 
    
    // Menyalakan LED 3
    digitalWrite(led1, HIGH);
    delay(700); // 
    digitalWrite(led1, LOW); // 
  }

}