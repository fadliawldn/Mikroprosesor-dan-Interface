// Deklarasi pin
const int button1 = 2;
const int button2 = 3;
const int button3 = 4;
const int led1 = 8;
const int led2 = 9;
const int led3 = 10;
int delayTime = 250; // Waktu delay untuk pergeseran LED

bool lastButton1State = LOW;
bool lastButton2State = LOW;
bool lastButton3State = LOW;

// Setup pin mode
void setup() {
  // Setup untuk tombol
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(button3, INPUT);
  
  // Setup untuk LED
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  
  // Inisialisasi semua LED mati
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
}

// Fungsi untuk LED ke kiri
void runLeft() {
  digitalWrite(led1, HIGH); // Nyalakan LED pertama
  delay(delayTime);
  digitalWrite(led1, LOW);  // Matikan LED pertama
  digitalWrite(led2, HIGH); // Nyalakan LED kedua
  delay(delayTime);
  digitalWrite(led2, LOW);  // Matikan LED kedua
  digitalWrite(led3, HIGH); // Nyalakan LED ketiga
  delay(delayTime);
  digitalWrite(led3, LOW);  // Matikan LED ketiga
}

// Fungsi untuk LED ke kanan
void runRight() {
  digitalWrite(led3, HIGH); // Nyalakan LED ketiga
  delay(delayTime);
  digitalWrite(led3, LOW);  // Matikan LED ketiga
  digitalWrite(led2, HIGH); // Nyalakan LED kedua
  delay(delayTime);
  digitalWrite(led2, LOW);  // Matikan LED kedua
  digitalWrite(led1, HIGH); // Nyalakan LED pertama
  delay(delayTime);
  digitalWrite(led1, LOW);  // Matikan LED pertama
}

// Fungsi untuk LED zig-zag (kanan ke kiri, kemudian kiri ke kanan)
void runZigZag() {
  // Dari kanan ke kiri
  runRight();
  
  // Dari kiri ke kanan
  runLeft();
}

// Fungsi utama loop
void loop() {
  // Membaca status tombol saat ini
  bool currentButton1State = digitalRead(button1);
  bool currentButton2State = digitalRead(button2);
  bool currentButton3State = digitalRead(button3);

  // Jika tombol 1 ditekan (deteksi tepi dari LOW ke HIGH untuk ke kiri)
  if (currentButton1State == HIGH && lastButton1State == LOW) {
    runLeft();
  }

  // Jika tombol 2 ditekan (deteksi tepi dari LOW ke HIGH untuk ke kanan)
  if (currentButton2State == HIGH && lastButton2State == LOW) {
    runRight();
  }

  // Jika tombol 3 ditekan (deteksi tepi dari LOW ke HIGH untuk zig-zag)
  if (currentButton3State == HIGH && lastButton3State == LOW) {
    runZigZag();
  }

  // Menyimpan status tombol untuk perbandingan pada iterasi berikutnya
  lastButton1State = currentButton1State;
  lastButton2State = currentButton2State;
  lastButton3State = currentButton3State;
}
