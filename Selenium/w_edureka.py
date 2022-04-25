from selenium import webdriver
from selenium.webdriver.common.keys import Keys
driver = webdriver.Chrome(executable_path="C:\EV_Files\ChromeDriver\chromedriver.exe")
driver.get("https://www.edureka.co/")
driver.find_element_by_xpath("/html/body/header/nav/div[3]/input").click()
driver.find_element_by_xpath('//*[@id="search-input"]').send_keys("python selenium")
driver.find_element_by_xpath('//*[@id="search-input"]').send_keys(Keys.ENTER)
