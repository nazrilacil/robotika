# tong sampah otomatis 
Alat dan Bahan:
1. *Arduino Uno* (atau board Arduino lain)
2. *Sensor Ultrasonik HC-SR04*
3. *Servo motor* untuk membuka dan menutup tong sampah
4. Kabel jumper
5. Sumber daya untuk Arduino (bisa pakai kabel USB atau power adapter)

Wiring (Sambungan Kabel):
- *Sensor HC-SR04*:
  - VCC -> 5V Arduino
  - GND -> GND Arduino
  - *Trig* -> Pin 9 Arduino
  - *Echo* -> Pin 10 Arduino

- *Servo Motor*:
  - VCC -> 5V Arduino
  - GND -> GND Arduino
  - *Signal* -> Pin 11 Arduino

Skema:
- Sensor Ultrasonik mengukur jarak.
- Jika ada objek di depan sensor dengan jarak tertentu (misalnya, kurang dari 20 cm), maka servo akan bergerak untuk membuka penutup tong sampah.
- Setelah beberapa detik, servo akan kembali ke posisi semula untuk menutup tong sampah.

Kode C++ untuk Arduino:


Penjelasan Kode:

1. *Pustaka Servo*: 
   - `#include <Servo.h>` adalah pustaka yang digunakan untuk mengendalikan servo motor.
   
2. *Inisialisasi Pin*:
   - `trigPin` dan `echoPin` adalah pin yang digunakan oleh sensor HC-SR04 untuk mengirimkan dan menerima pulsa.
   - `servoPin` adalah pin yang digunakan untuk mengendalikan servo motor.

3. *Sensor Ultrasonik*:
   - Untuk mendapatkan jarak, sensor mengirimkan pulsa dan mengukur berapa lama waktu yang dibutuhkan untuk pulsa kembali (dari objek).
   - Jarak dihitung dengan rumus `distance = duration * 0.034 / 2`, di mana `0.034` adalah kecepatan suara dalam cm per mikrodetik.

4. *Servo Motor*:
   - Servo motor dipasang pada pin 11 dan dikendalikan menggunakan pustaka `Servo.h`.
   - Servo akan bergerak ke *90 derajat* (posisi terbuka) jika objek terdeteksi di jarak kurang dari 20 cm dan kembali ke *0 derajat* (posisi tertutup) setelah 5 detik.

5. *Pengulangan Loop*:
   - Kode di dalam `loop()` akan terus berjalan selama Arduino menyala.
   - Setiap kali sensor mendeteksi objek dengan jarak kurang dari 20 cm, servo akan terbuka dan menutup setelah 5 detik.

# python 
kalo liat orang 😆  
2. *Deteksi gerakan tangan* (gesture)  
3. *Klasifikasi sampah* → organik / non-organik pake *Machine Learning*  
4. *Monitoring kamera real-time* dari webcam atau kamera USB  
5. *Buka otomatis kalo ada benda mendekat* (pakai kamera, bukan sensor ultrasonik)

---

Kombinasi Ideal:
- *Hardware:* Raspberry Pi + kamera USB
- *Software:* Python + OpenCV + Servo motor
- *Kode contoh sederhana:*
