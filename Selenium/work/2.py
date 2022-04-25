import os
import time
from selenium import webdriver
from selenium.webdriver.chrome.service import Service
# os.environ['PATH'] += "C:\EV_Files\ChromeDriver\chromedriver.exe"
# s=Service("C:\EV_Files\ChromeDriver\chromedriver.exe")
# driver = webdriver.Chrome(service=s)
driver = webdriver.Chrome("C:\EV_Files\ChromeDriver\chromedriver.exe")
driver.get("https://www.w3schools.com/")
print(driver.title)
driver.get("https://www.javatpoint.com/")
print(driver.title)
driver.back()
print(driver.title)
driver.forward()
print(driver.title)
driver.quit()