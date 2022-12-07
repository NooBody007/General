from selenium import webdriver
import time

browser = webdriver.Firefox()

browser.get("https://twitter.com/")
time.sleep(3)
giriş_yap = browser.find_element_by_xpath("//*[@id='react-root']/div/div/div/main/div/div/div/div[1]/div/div[3]/a[2]")
giriş_yap.click()
time.sleep(5)

username = browser.find_element_by_xpath("//*[@id='react-root']/div/div/div[2]/main/div/div/div[2]/form/div/div[1]/label/div/div[2]/div/input")
password = browser.find_element_by_xpath("//*[@id='react-root']/div/div/div[2]/main/div/div/div[2]/form/div/div[2]/label/div/div[2]/div/input")

username.send_keys("username")
password.send_keys("passwd")
time.sleep(2)

login = browser.find_element_by_xpath("//*[@id='react-root']/div/div/div[2]/main/div/div/div[2]/form/div/div[3]/div")
login.click()

time.sleep(3)

searchbar = browser.find_element_by_xpath("//*[@id='react-root']/div/div/div[2]/main/div/div/div/div[2]/div/div[2]/div/div/div/div[1]/div/div/div/form/div[1]/div/div/div[2]/input")
searchbar.click()
searchbar.send_keys("#usdtry")
time.sleep(5)

searchbtn = browser.find_element_by_xpath("//*[@id='typeaheadDropdown-1']/div[2]/div/div/div/span/span")
searchbtn.click()
time.sleep(4)

tweets = []
lenOfPage = browser.execute_script("window.scrollTo(0, document.body.scrollHeight);var lenOfPage=document.body.scrollHeight;return lenOfPage;")
match=False
while(match==False):
    lastCount = lenOfPage
    time.sleep(5)
    elements = browser.find_elements_by_css_selector(".css-901oao.css-16my406.r-poiln3.r-bcqeeo.r-qvutc0")
    for element in elements:
        tweets.append(element.text)
    lenOfPage = browser.execute_script("window.scrollTo(0, document.body.scrollHeight);var lenOfPage=document.body.scrollHeight;return lenOfPage;")
    if lastCount == lenOfPage:
        match=True

time.sleep(3)

tweetcount = 1
with open("tweets.txt","w",encoding="utf-8") as file:
    for tweet in tweets:
        file.write(str(tweetcount)+".\n" + tweet+"\n")
        file.write("************************\n")
        tweetcount += 1

browser.close()
