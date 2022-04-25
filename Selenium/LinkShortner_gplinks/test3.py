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


pyautogui.scroll(-10000)
x_pos = 900

# Open/Download [ Correct ]
for i in range(820,920,10):
    driver.switch_to.window(driver.window_handles[0])
    pyautogui.scroll(-10000)
    pyautogui.moveTo(x=x_pos, y=i)
    pyautogui.click()

# Open - Continue [Correct]
for i in range(330,380,10):
    driver.switch_to.window(driver.window_handles[0])
    pyautogui.scroll(-10000)
    pyautogui.moveTo(x=x_pos, y=i)
    pyautogui.click()

pyautogui.scroll(-1000)
time.sleep(12)

# Open/Download [ Correct ]
for i in range(820,920,10):
    driver.switch_to.window(driver.window_handles[0])
    pyautogui.scroll(-10000)
    pyautogui.moveTo(x=x_pos, y=i)
    pyautogui.click()

# Open - Continue [Correct]
for i in range(330,380,10):
    driver.switch_to.window(driver.window_handles[0])
    pyautogui.scroll(-10000)
    pyautogui.moveTo(x=x_pos, y=i)
    pyautogui.click()

pyautogui.scroll(-1000)
time.sleep(12)

# Unlock Link & Get Link
for i in range(260,340,10):
    driver.switch_to.window(driver.window_handles[0])
    pyautogui.scroll(-10000)
    pyautogui.moveTo(x=x_pos, y=i)
    pyautogui.click()

# Unlock Link & Get Link
for i in range(260,340,10):
    driver.switch_to.window(driver.window_handles[0])
    pyautogui.scroll(-10000)
    pyautogui.moveTo(x=x_pos, y=i)
    pyautogui.click()
    
time.sleep(20)


# Unlock Link & Get Link
for i in range(260,340,10):
    driver.switch_to.window(driver.window_handles[0])
    pyautogui.scroll(-10000)
    pyautogui.moveTo(x=x_pos, y=i)
    pyautogui.click()


