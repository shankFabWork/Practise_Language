import time
import os
import pyautogui
import time
from selenium import webdriver
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.chrome.options import Options

os.system("conda activate base")

from selenium import webdriver
from selenium.webdriver.common.keys import Keys
path="C:\EV_Files\ChromeDriver\chromedriver.exe"
chrome_options = webdriver.ChromeOptions()
chrome_options.add_argument("--disable-notifications")
chrome_options.add_argument("--disable-popup-blocking")
opts = Options()
# opts.add_experimental_option("debuggerAddress","localhost:9788")
driver = webdriver.Chrome(executable_path="C:\EV_Files\ChromeDriver\chromedriver.exe")
driver.implicitly_wait(5)
driver.maximize_window()
driver.get("https://gplinks.co/KBPqe")


x_pos = 900
for i in range(140,900,20):
    driver.switch_to.window(driver.window_handles[0])
    pyautogui.scroll(-10000)
    pyautogui.moveTo(x=x_pos, y=i)
    pyautogui.click()

driver.switch_to.window(driver.window_handles[0])
pyautogui.scroll(-10000)
pyautogui.moveTo(1885,170)
pyautogui.click()

x_pos = 900
for i in range(140,900,20):
    driver.switch_to.window(driver.window_handles[0])
    pyautogui.scroll(-10000)
    pyautogui.moveTo(x=x_pos, y=i)
    pyautogui.click()

x_pos = 900
for i in range(140,900,20):
    driver.switch_to.window(driver.window_handles[0])
    pyautogui.scroll(-10000)
    pyautogui.moveTo(x=x_pos, y=i)
    pyautogui.click()


time.wait(14)

x_pos = 900
for i in range(140,900,20):
    driver.switch_to.window(driver.window_handles[0])
    pyautogui.scroll(-10000)
    pyautogui.moveTo(x=x_pos, y=i)
    pyautogui.click()

x_pos = 900
for i in range(140,900,20):
    driver.switch_to.window(driver.window_handles[0])
    pyautogui.scroll(-10000)
    pyautogui.moveTo(x=x_pos, y=i)
    pyautogui.click()

x_pos = 900
for i in range(140,900,20):
    driver.switch_to.window(driver.window_handles[0])
    pyautogui.scroll(-10000)
    pyautogui.moveTo(x=x_pos, y=i)
    pyautogui.click()


time.wait(20)


