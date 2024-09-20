#define LED1 2 //deklarasi pin led1 dengan #define
int LED2 = 3; //deklarasi pin led2 dengan tipe data nama variabel
const int LED3 = 4; //deklarasi pin led3 dengan constanta tipe data dan nama variabel agar nilai variabelnya tidak bisa diubah-ubah

void setup() //bagian untuk inisialisasi parameter awal
{
  pinMode(LED1, OUTPUT); //setup pin led1 sebagai output
  pinMode(LED2, OUTPUT); //setup pin sebagai output
  pinMode(LED3, OUTPUT); //setup pin sebagai output
}

void loop() //program utama yang dijalankan terus-menerus
{
  /*digitalWrite(LED1, 1); 
  digitalWrite(LED3, 0);
  delay(1000); //lama waktu led1 menyala selama 1000 milidetik
  digitalWrite(LED1, 0);
  digitalWrite(LED2, 1);
  delay(1000);
  digitalWrite(LED2, 0);
  digitalWrite(LED3, 1);
  delay(1000);*/ //menyalakan led secara bergaintian
  digitalWrite(LED1, HIGH);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);
  delay(1000);
 digitalWrite(LED1, LOW);
  digitalWrite(LED2, HIGH);
  digitalWrite(LED3, LOW);
  delay(1000);
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, HIGH);
  delay(1000);
  
}