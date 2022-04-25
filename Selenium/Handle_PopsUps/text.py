import time
from selenium import webdriver
from selenium.webdriver.common.keys import Keys
driver = webdriver.Chrome(executable_path="C:\EV_Files\ChromeDriver\chromedriver.exe")
driver.get("https://birdurls.com/ru1hZL")
time.sleep(2)
driver.find_element_by_xpath('//*[@id="recaptcha-anchor"]/div[1]').click()
# driver.find_element_by_name('search_query').send_keys("study")
# driver.find_element_by_name('search_query').send_keys(Keys.ENTER)


