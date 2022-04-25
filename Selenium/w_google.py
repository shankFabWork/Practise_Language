from selenium import webdriver
from selenium.webdriver.common.keys import Keys
driver = webdriver.Chrome(executable_path="C:\EV_Files\ChromeDriver\chromedriver.exe")

# Open "Google.com"
driver.get("http://google.com/")

# Search Text
search_txt = "poco x3 pro"
driver.find_element_by_xpath('/html/body/div[1]/div[3]/form/div[1]/div[1]/div[1]/div/div[2]/input').send_keys(search_txt)

# Click Enter on Google
driver.find_element_by_xpath('/html/body/div[1]/div[3]/form/div[1]/div[1]/div[1]/div/div[2]/input').send_keys(Keys.ENTER)
