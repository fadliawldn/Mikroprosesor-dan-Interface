// Definisikan pin untuk setiap segmen dari seven segment
const int segA = 13;
const int segB = 12;
const int segC = 11;
const int segD = 10;
const int segE = 9;
const int segF = 8;
const int segG = 7;

// Variabel counter
int counter = 0;

// Timer untuk counter
unsigned long previousMillis = 0; 
const long interval = 1000; // interval 1 detik

// Array yang menyimpan pola segmen untuk angka 0-9
const byte digitPatterns[10][7] = {
  {HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, LOW},   // 0
  {LOW, HIGH, HIGH, LOW, LOW, LOW, LOW},       // 1
  {HIGH, HIGH, LOW, HIGH, HIGH, LOW, HIGH},    // 2
  {HIGH, HIGH, HIGH, HIGH, LOW, LOW, HIGH},    // 3
  {LOW, HIGH, HIGH, LOW, LOW, HIGH, HIGH},     // 4
  {HIGH, LOW, HIGH, HIGH, LOW, HIGH, HIGH},    // 5
  {HIGH, LOW, HIGH, HIGH, HIGH, HIGH, HIGH},   // 6
  {HIGH, HIGH, HIGH, LOW, LOW, LOW, LOW},      // 7
  {HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH},  // 8
  {HIGH, HIGH, HIGH, HIGH, LOW, HIGH, HIGH}    // 9
};

void setup() {
  // Inisialisasi pin sebagai output
  pinMode(segA, OUTPUT);
  pinMode(segB, OUTPUT);
  pinMode(segC, OUTPUT);
  pinMode(segD, OUTPUT);
  pinMode(segE, OUTPUT);
  pinMode(segF, OUTPUT);
  pinMode(segG, OUTPUT);
  
  // Inisialisasi awal seven segment
  displayDigit(counter);
}

void loop() {
  // Ambil waktu saat ini
  unsigned long currentMillis = millis();

  // Jika sudah melewati interval waktu
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;  // Reset timer

    // Update counter
    counter++;

    // Jika counter lebih dari 9, reset ke 0
    if (counter > 9) {
      counter = 0;
    }

    // Tampilkan angka baru di seven segment
    displayDigit(counter);
  }
}

// Fungsi untuk menampilkan angka pada seven segment
void displayDigit(int number) {
  // Menulis pola segmen ke pin seven segment
  digitalWrite(segA, digitPatterns[number][0]);
  digitalWrite(segB, digitPatterns[number][1]);
  digitalWrite(segC, digitPatterns[number][2]);
  digitalWrite(segD, digitPatterns[number][3]);
  digitalWrite(segE, digitPatterns[number][4]);
  digitalWrite(segF, digitPatterns[number][5]);
  digitalWrite(segG, digitPatterns[number][6]);
}