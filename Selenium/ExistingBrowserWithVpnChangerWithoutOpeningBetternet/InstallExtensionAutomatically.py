
from selenium import webdriver
from selenium.webdriver.chrome.options import Options
import os
import pyautogui
import time

opts = Options()
opts.add_extension("VPN_Master.crx")
driver = webdriver.Chrome(executable_path="C:\EV_Files\ChromeDriver\chromedriver.exe",options=opts)
driver.maximize_window()
driver.get("https://techbubbleking.blogspot.com/2021/10/login-automatically-in-facebook.html")

# Puzzle Icon
pyautogui.moveTo(1810,65)
pyautogui.click()

# Pin Icon
pyautogui.moveTo(1750,230)
pyautogui.click()

# Window Click
pyautogui.moveTo(1735,10)
pyautogui.click()

# Extension Icon
pyautogui.moveTo(1770,60)
pyautogui.click()

# Wait for 2 seconds
time.sleep(2)

# Connect Button
pyautogui.moveTo(1565,440)
pyautogui.click()

# Wait for 5 seconds
time.sleep(5)


