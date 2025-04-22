#include <Servo.h>  // Menggunakan library servo untuk kontrol motor

// Pin untuk sensor Ultrasonik
const int trigPin = 9;   // Pin untuk Trig
const int echoPin = 10;  // Pin untuk Echo

// Pin untuk Servo Motor
const int servoPin = 11;

Servo myServo;           // Membuat objek servo

// Variabel untuk menyimpan jarak
long duration;
int distance;

void setup() {
  // Inisialisasi pin
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  // Inisialisasi servo motor
  myServo.attach(servoPin); // Hubungkan servo ke pin 11
  myServo.write(0);         // Servo di posisi tertutup (0 derajat)
  
  Serial.begin(9600);       // Memulai komunikasi serial untuk debugging
}

void loop() {
  // Mengirimkan pulsa ke sensor Ultrasonik
  digitalWrite(trigPin, LOW);  
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);  
  digitalWrite(trigPin, LOW);

  // Menghitung durasi echo yang kembali
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;  // Menghitung jarak (cm)
  
  // Menampilkan jarak untuk debugging
  Serial.print("Jarak: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Jika jarak kurang dari 20 cm, buka penutup tong sampah
  if (distance < 20) {
    Serial.println("Objek terdeteksi! Membuka penutup tong sampah...");
    myServo.write(90);  // Buka penutup (90 derajat)
    delay(5000);         // Biarkan terbuka selama 5 detik
    myServo.write(0);    // Tutup kembali penutup (0 derajat)
    Serial.println("Penutup tertutup!");
  }
delay(500);  // Memberikan jeda untuk pembacaan berikutnya
}
