# Imports
import time
from selenium import webdriver
from selenium.webdriver.common.keys import Keys
driver = webdriver.Chrome(executable_path="C:\EV_Files\ChromeDriver\chromedriver.exe")
driver.get("https://www.youtube.com/")
driver.execute_script('window.open("https://maps.google.com")')
driver.execute_script('window.open("https://www.javatpoint.com/");')

print(driver.current_url)

# time.sleep to slow down the process otherwise u will not be able to see
time.sleep(3)

# 3 tabs are opened , it is switch 1 index [ 2nd ] tab 
driver.switch_to.window(driver.window_handles[1])

time.sleep(3)
driver.switch_to.window(driver.window_handles[2])

time.sleep(3)
driver.close()
driver.switch_to.window(driver.window_handles[1])

# Close recently switched tab , in this case it is "1" index tab 
driver.close()