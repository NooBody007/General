from selenium import webdriver
import time

browser = webdriver.Firefox()

url = "https://www.instagram.com/"

browser.get(url)
time.sleep(2)
username = browser.find_element_by_name("username")
password = browser.find_element_by_name("password")

username.send_keys("username")
password.send_keys("passwd")
time.sleep(3)

login = browser.find_element_by_xpath("//*[@id='loginForm']/div/div[3]/button/div")
login.click()
time.sleep(4)

nn1 = browser.find_element_by_xpath("//*[@id='react-root']/section/main/div/div/div/div/button")
nn1.click()
time.sleep(4)

nn2 = browser.find_element_by_css_selector(".aOOlW.HoLwm")
nn2.click()
time.sleep(4)

profile = browser.find_element_by_xpath("//*[@id='react-root']/section/nav/div[2]/div/div/div[3]/div/div[5]/span")
profile.click()
time.sleep(2)

profile2= browser.find_element_by_xpath("//*[@id='react-root']/section/nav/div[2]/div/div/div[3]/div/div[5]/div[2]/div[2]/div[2]/a[1]")
profile2.click()
time.sleep(4)

followers_selector = browser.find_element_by_css_selector(".LH36I")
followers_button = followers_selector[1]
followers_button.click()

followers = browser.find_element_by_xpath("//*[@id='react-root']/section/main/div/header/section/ul/li[2]/a")
followers.click()
time.sleep(2)


jscommand = """
followers = document.querySelector(".isgrP");
followers.scrollTo(0,followers.scrollHeight);
var lenOfPage=followers.scrollHeight;
return lenOfPage;
"""
lenOfPage = browser.execute_script(jscommand)
match=False
while(match==False):
    lastCount = lenOfPage
    time.sleep(3)
    lenOfPage = browser.execute_script(jscommand)
    if lastCount == lenOfPage:
        match=True
time.sleep(3)

flist = []
follower_name = browser.find_elements_by_css_selector(".FPmhX.notranslate._0imsa")
for follower in follower_name:
    flist.append(follower.text)

counter = 1
with open("followers.txt","w",encoding="utf-8") as file:
    for follower in flist:
        file.write(str(counter) + ".\n" + follower + "\n")
        file.write("***************\n")
        counter += 1
time.sleep(1)

browser.close()
