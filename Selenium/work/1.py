import os
import time
from selenium import webdriver
from selenium.webdriver.chrome.service import Service
# os.environ['PATH'] += "C:\EV_Files\ChromeDriver\chromedriver.exe"
# s=Service("C:\EV_Files\ChromeDriver\chromedriver.exe")
# driver = webdriver.Chrome(service=s)
driver = webdriver.Chrome("C:\EV_Files\ChromeDriver\chromedriver.exe")
driver.get("http://demo.automationtesting.in/Windows.html")
print(driver.title)
print(driver.current_url)
time.sleep(1)   
driver.find_element_by_xpath('//*[@id="Tabbed"]/a/button').click()
time.sleep(1)   
# driver.find_element_by_class_name("btn btn-info").click()
# driver.find_element_by_xpath('/html/body/div[1]/div/div/div/div[2]/div[1]/a/button').click()
# driver.close()
driver.quit()