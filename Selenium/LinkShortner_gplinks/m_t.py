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
driver1 = webdriver.Chrome(executable_path=path)
driver2 = webdriver.Chrome(executable_path=path)
driver3 = webdriver.Chrome(executable_path=path)

driver1.maximize_window()
driver1.get("https://google.com")

driver2.maximize_window()
driver2.get("https://google.com")

driver3.maximize_window()
driver3.get("https://google.com")