// Pin untuk lampu lalu lintas jalur 1
int red1 = 2;
int yellow1 = 3;
int green1 = 4;

// Pin untuk lampu lalu lintas jalur 2
int red2 = 5;
int yellow2 = 6;
int green2 = 7;

// Pin untuk lampu lalu lintas jalur 3
int red3 = 8;
int yellow3 = 9;
int green3 = 10;

// Waktu delay (dalam milidetik)
int greenTime = 5000;   // Waktu lampu hijau menyala (5 detik)
int yellowTime = 2000;  // Waktu lampu kuning menyala (2 detik)
int redTime = 5000;     // Waktu lampu merah menyala (5 detik)

void setup() {
  // Atur semua pin sebagai output
  pinMode(red1, OUTPUT);
  pinMode(yellow1, OUTPUT);
  pinMode(green1, OUTPUT);

  pinMode(red2, OUTPUT);
  pinMode(yellow2, OUTPUT);
  pinMode(green2, OUTPUT);

  pinMode(red3, OUTPUT);
  pinMode(yellow3, OUTPUT);
  pinMode(green3, OUTPUT);
}

void loop() {
  // Jalur 1 Hijau, Jalur 2 & 3 Merah
  digitalWrite(green1, HIGH);  // Nyalakan hijau jalur 1
  digitalWrite(red1, LOW);
  digitalWrite(red2, HIGH);    // Nyalakan merah jalur 2
  digitalWrite(red3, HIGH);    // Nyalakan merah jalur 3
  delay(greenTime);            // Tunggu selama lampu hijau jalur 1
  digitalWrite(green1, LOW);   // Matikan hijau jalur 1
  digitalWrite(yellow1, HIGH); // Nyalakan kuning jalur 1
  delay(yellowTime);           // Tunggu kuning
  digitalWrite(yellow1, LOW);  // Matikan kuning jalur 1
  digitalWrite(red1, HIGH);    // Nyalakan merah jalur 1

  // Jalur 2 Hijau, Jalur 1 & 3 Merah
  digitalWrite(red2, LOW);
  digitalWrite(green2, HIGH);  // Nyalakan hijau jalur 2
  digitalWrite(red1, HIGH);    // Nyalakan merah jalur 1
  digitalWrite(red3, HIGH);    // Nyalakan merah jalur 3
  delay(greenTime);            // Tunggu selama lampu hijau jalur 2
  digitalWrite(green2, LOW);   // Matikan hijau jalur 2
  digitalWrite(yellow2, HIGH); // Nyalakan kuning jalur 2
  delay(yellowTime);           // Tunggu kuning
  digitalWrite(yellow2, LOW);  // Matikan kuning jalur 2
  digitalWrite(red2, HIGH);    // Nyalakan merah jalur 2

  // Jalur 3 Hijau, Jalur 1 & 2 Merah
  digitalWrite(red3, LOW);
  digitalWrite(green3, HIGH);  // Nyalakan hijau jalur 3
  digitalWrite(red1, HIGH);    // Nyalakan merah jalur 1
  digitalWrite(red2, HIGH);    // Nyalakan merah jalur 2
  delay(greenTime);            // Tunggu selama lampu hijau jalur 3
  digitalWrite(green3, LOW);   // Matikan hijau jalur 3
  digitalWrite(yellow3, HIGH); // Nyalakan kuning jalur 3
  delay(yellowTime);           // Tunggu kuning
  digitalWrite(yellow3, LOW);  // Matikan kuning jalur 3
  digitalWrite(red3, HIGH);    // Nyalakan merah jalur 3
}