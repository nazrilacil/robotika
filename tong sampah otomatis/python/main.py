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
