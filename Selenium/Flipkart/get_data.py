import time
from selenium import webdriver
from selenium.webdriver.common.keys import Keys
driver = webdriver.Chrome(executable_path="C:\EV_Files\ChromeDriver\chromedriver.exe")
driver.maximize_window()
driver.get("https://www.flipkart.com/")
time.sleep(2)
driver.find_element_by_xpath("/html/body/div[2]/div/div/button").click()
driver.find_element_by_class_name("_3704LK").click()
driver.find_element_by_class_name("_3704LK").send_keys("mobiles")
driver.find_element_by_xpath('//*[@id="container"]/div/div[1]/div[1]/div[2]/div[2]/form/div/button').click()
