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
driver = webdriver.Chrome(executable_path="C:\EV_Files\ChromeDriver\chromedriver.exe")

link_arr = [
    "https://google.com",
    "https://facebook.com"
]
link_length = len(link_arr)
window_dict={}
for i in range(link_length):

    window_dict["l{}".format(i)]=driver
    driver.maximize_window()
    driver.get(link_arr[i])

for i in range(link_length):
    driver = window_dict["l{}".format(i)]
    driver.switch_to_window(driver.window_handles[1])
    time.sleep(2)
