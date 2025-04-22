import cv2
import RPi.GPIO as GPIO
import time

servo_pin = 17
GPIO.setmode(GPIO.BCM)
GPIO.setup(servo_pin, GPIO.OUT)

servo = GPIO.PWM(servo_pin, 50)
servo.start(0)

def buka_tutup(buka=True):
    if buka:
        servo.ChangeDutyCycle(7)  # posisi buka
    else:
        servo.ChangeDutyCycle(2)  # posisi tutup
    time.sleep(0.5)

cap = cv2.VideoCapture(0)

while True:
    ret, frame = cap.read()
    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
    
    # bisa ditambah model deteksi wajah atau objek
    if gray.mean() < 50:  # contoh kondisi sederhana

buka_tutup(True)
