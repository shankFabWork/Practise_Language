# Selenium Imports
from selenium import webdriver
from selenium.webdriver.common.keys import Keys
driver = webdriver.Chrome(executable_path="C:\EV_Files\ChromeDriver\chromedriver.exe")

# Website Name
driver.get("https://www.facebook.com/")
username = driver.find_element_by_xpath('//*[@id="email"]')

# print(username.is_displayed())
# print(username.is_enabled())

username.click()

# write 10 digit mobile number or gmail
mobile_or_email_no = "5363246784" 
username.send_keys()

# write password
password = "dfjsndf"
password = driver.find_element_by_xpath('//*[@id="pass"]')
password.send_keys(password)

# It will click login button
driver.find_element_by_xpath("/html/body/div[1]/div[2]/div[1]/div/div/div/div[2]/div/div[1]/form/div[2]/button").click()  
