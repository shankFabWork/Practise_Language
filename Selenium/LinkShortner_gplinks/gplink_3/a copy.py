import time
import os
import pyautogui
import time
import threading
from selenium import webdriver
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.chrome.options import Options


path="C:\EV_Files\ChromeDriver\chromedriver.exe"
chrome_options = webdriver.ChromeOptions()
chrome_options.add_argument("--disable-notifications")
chrome_options.add_argument("--disable-popup-blocking")
opts = Options()
# opts.add_experimental_option("debuggerAddress","localhost:9788")
driver = webdriver.Chrome(executable_path="C:\EV_Files\ChromeDriver\chromedriver.exe")
driver.implicitly_wait(20)
driver.maximize_window()
driver.get("https://gplinks.co/q6c2K5")


# Open/Download
try:
    driver.find_element_by_class_name("video-download").click()
except:
    pass

try:
    driver.switch_to.window(driver.window_handles[0])
    pyautogui.scroll(-1000)
    time.sleep(15)
except:
    pass

try:
    pyautogui.scroll(-10000)
    driver.find_element_by_id("btn6").click()
    driver.switch_to.window(driver.window_handles[0])
except:
    pass

# Open/Download
try:
    driver.find_element_by_class_name("video-download").click()
    driver.switch_to.window(driver.window_handles[0])
    pyautogui.scroll(-10000)
except:
    pass

# Open - Continue
try:
    driver.find_element_by_id("btn6").click()
    driver.switch_to.window(driver.window_handles[0])
    pyautogui.scroll(-1000)
    time.sleep(15)
except:
    pass

pyautogui.scroll(-10000)

#Unlock Link
try:
    driver.find_element_by_id("unlock-btn").click()
    driver.switch_to.window(driver.window_handles[0])
    pyautogui.scroll(-1000)
except:
    pass

try:
    driver.find_element_by_id("unlock-btn").click()
    driver.switch_to.window(driver.window_handles[0])
    pyautogui.scroll(-1000)
except:
    pass

try:
    driver.find_element_by_id("unlock-btn").click()
    driver.switch_to.window(driver.window_handles[0])
    pyautogui.scroll(-1000)
    time.sleep(20)
except:
    pass

# Get Link
try:
    driver.find_element_by_id("link-btn").click()
    driver.switch_to.window(driver.window_handles[0])
except:
    pass

driver.close()
