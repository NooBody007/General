from selenium import webdriver
import time
import random

browser = webdriver.Firefox()

url = "https://eksisozluk.com/daft-punk--63921?p="

pagecount = 1
entries =[]
entrycount = 1
while pagecount <= 10:
    randompage = random.randint(1,121)
    newUrl = url + str(randompage)
    browser.get(newUrl)
    elements = browser.find_elements_by_css_selector(".content")
    for i in elements:
        entries.append(i.text)
    time.sleep(3)
    pagecount += 1

for i in entries:
    print("*************")
    print(i)

with open("entries.txt","w",encoding="utf-8")as file:
    for entry in entries:
        file.write(str(entrycount)+".\n"+entry+"\n")
        file.write("********************\n")
        entrycount +=1

browser.close()

"""
elements = browser.find_elements_by_css_selector(".content")

for i in elements:
    print("********************")
    print(i.text)
    
browser.close()
"""

