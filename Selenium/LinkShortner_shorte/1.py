import time
import os
from selenium import webdriver
from selenium.webdriver.common.keys import Keys
path="C:\EV_Files\ChromeDriver\chromedriver.exe"
chrome_options = webdriver.ChromeOptions()
chrome_options.add_argument("--disable-notifications")
chrome_options.add_argument("--disable-popup-blocking")
driver=webdriver.Chrome(path,chrome_options=chrome_options)
driver.implicitly_wait(5)
driver.maximize_window()
# driver.get("http://gestyy.com/epTfUh")

driver.get("https://gplinks.co/KBPqe")
time.sleep(5)
# driver.find_element_by_xpath('//*[@id="skip_button"]').click()




