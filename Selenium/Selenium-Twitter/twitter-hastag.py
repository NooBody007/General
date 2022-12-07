from selenium import webdriver
import time
import random

liste = "123456"

while True:
    psw = random.choices(liste,k=3)
    psw = "".join(psw)
    print("************"+psw+"*****************")
