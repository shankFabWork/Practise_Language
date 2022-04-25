import time
import os
import pyautogui
import time
from selenium import webdriver
from selenium.webdriver.common.keys import Keys

os.system("conda activate base")

no_of_loop = 20
for i in range(no_of_loop):
    path="C:\EV_Files\ChromeDriver\chromedriver.exe"
    chrome_options = webdriver.ChromeOptions()
    chrome_options.add_argument("--disable-notifications")
    chrome_options.add_argument("--disable-popup-blocking")
    driver=webdriver.Chrome(path,chrome_options=chrome_options)
    driver.maximize_window()

    driver.get("https://gplinks.co/reUKEm")
    
    time.sleep(25)
    pyautogui.moveTo(x=330, y=265)
    pyautogui.click()
    pyautogui.moveTo(x=1890, y=173)
    pyautogui.click()
    pyautogui.click()
    time.sleep(2)
    pyautogui.moveTo(x=1797, y=181)
    pyautogui.click(clicks=2, interval=0.25)
    time.sleep(5)
    driver.close()




