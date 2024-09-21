#include <Arduino.h>

char angka = 1;
int c = 6;
int d = 7;
int e = 8;
int b = 9;
int a = 10;
int f = 11;
int g = 12;
#define s1 digitalRead(13)
#define s2 digitalRead(5)

bool isCountingUp = false; // Flag untuk menghitung naik
bool isCountingDown = false; // Flag untuk menghitung turun

void setup() {
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(13, INPUT_PULLUP); // PB1
  pinMode(5, INPUT_PULLUP);  // PB2
}

void tampilkan_angka(void) {
  // Tampilan untuk masing-masing angka pada 7-segment
  switch (angka) {
    case 0:
      digitalWrite(a, HIGH); digitalWrite(b, HIGH); digitalWrite(c, HIGH); 
      digitalWrite(d, HIGH); digitalWrite(e, HIGH); digitalWrite(f, HIGH); digitalWrite(g, LOW);
      break;
    case 1:
      digitalWrite(a, LOW); digitalWrite(b, HIGH); digitalWrite(c, HIGH);
      digitalWrite(d, LOW); digitalWrite(e, LOW); digitalWrite(f, LOW); digitalWrite(g, LOW);
      break;
    case 2:
      digitalWrite(a, HIGH); digitalWrite(b, HIGH); digitalWrite(c, LOW);
      digitalWrite(d, HIGH); digitalWrite(e, HIGH); digitalWrite(f, LOW); digitalWrite(g, HIGH);
      break;
    case 3:
      digitalWrite(a, HIGH); digitalWrite(b, HIGH); digitalWrite(c, HIGH);
      digitalWrite(d, HIGH); digitalWrite(e, LOW); digitalWrite(f, LOW); digitalWrite(g, HIGH);
      break;
    case 4:
      digitalWrite(a, LOW); digitalWrite(b, HIGH); digitalWrite(c, HIGH);
      digitalWrite(d, LOW); digitalWrite(e, LOW); digitalWrite(f, HIGH); digitalWrite(g, HIGH);
      break;
    case 5:
      digitalWrite(a, HIGH); digitalWrite(b, LOW); digitalWrite(c, HIGH);
      digitalWrite(d, HIGH); digitalWrite(e, LOW); digitalWrite(f, HIGH); digitalWrite(g, HIGH);
      break;
    case 6:
      digitalWrite(a, HIGH); digitalWrite(b, LOW); digitalWrite(c, HIGH);
      digitalWrite(d, HIGH); digitalWrite(e, HIGH); digitalWrite(f, HIGH); digitalWrite(g, HIGH);
      break;
    case 7:
      digitalWrite(a, HIGH); digitalWrite(b, HIGH); digitalWrite(c, HIGH);
      digitalWrite(d, LOW); digitalWrite(e, LOW); digitalWrite(f, LOW); digitalWrite(g, LOW);
      break;
    case 8:
      digitalWrite(a, HIGH); digitalWrite(b, HIGH); digitalWrite(c, HIGH);
      digitalWrite(d, HIGH); digitalWrite(e, HIGH); digitalWrite(f, HIGH); digitalWrite(g, HIGH);
      break;
    case 9:
      digitalWrite(a, HIGH); digitalWrite(b, HIGH); digitalWrite(c, HIGH);
      digitalWrite(d, HIGH); digitalWrite(e, LOW); digitalWrite(f, HIGH); digitalWrite(g, HIGH);
      break;
  }
}

void loop() {
  // Cek apakah tombol 1 (PB1) ditekan, untuk menghitung naik
  if (s1 == LOW && !isCountingUp) {
    isCountingUp = true;    // Mulai menghitung naik
    isCountingDown = false; // Matikan hitung turun
  }

  // Cek apakah tombol 2 (PB2) ditekan, untuk menghitung turun
  if (s2 == LOW && !isCountingDown) {
    isCountingDown = true;  // Mulai menghitung turun
    isCountingUp = false;   // Matikan hitung naik
  }

  // Proses hitung naik
  if (isCountingUp) {
    angka++;               // Naikkan angka
    if (angka > 9) {
      angka = 1;           // Kembali ke 1 jika lebih dari 9
    }
    tampilkan_angka();     // Tampilkan angka
    delay(500);            // Beri jeda 500ms
  }

  // Proses hitung turun
  if (isCountingDown) {
    angka--;               // Turunkan angka
    if (angka < 1) {
      angka = 9;           // Kembali ke 9 jika kurang dari 1
    }
    tampilkan_angka();     // Tampilkan angka
    delay(500);            // Beri jeda 500ms
  }
}
