# Open Udemy And Search In That

# Selenium Imports
from selenium import webdriver
from selenium.webdriver.common.keys import Keys

# Chrome Drive Location
driver = webdriver.Chrome(executable_path="C:\EV_Files\ChromeDriver\chromedriver.exe")

# Write Website Name
driver.get("https://www.udemy.com/")

# Search Text
search_txt = "poco x3 pro"
driver.find_element_by_name("q").send_keys(search_txt)
driver.find_element_by_name("q").send_keys(Keys.ENTER)

# driver.find_element_by_name("q")
# driver.find_element_by_id("u1110-search-form-autocomplete--3").click()

# driver.find_element_by_xpath('//*[@id="u210-search-form-autocomplete--3"]').click()
# driver.find_element_by_xpath('//*[@id="u210-search-form-autocomplete--3"]').send_keys("poco x3 pro")
# driver.find_element_by_xpath('//*[@id="u210-search-form-autocomplete--3"]').send_keys(Keys.ENTER)


