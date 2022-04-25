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

opts = Options()
opts = webdriver.ChromeOptions()
opts.add_argument("--disable-notifications")
opts.add_argument("--disable-popup-blocking")
opts.add_argument('--proxy-server=46.102.106.37:13228')
driver = webdriver.Chrome(executable_path="C:\EV_Files\ChromeDriver\chromedriver.exe",chrome_options=opts)
driver.implicitly_wait(5)
driver.maximize_window()
driver.get("https://gplinks.co/KBPqe")

pyautogui.moveTo(x=940, y=865)
pyautogui.click()

driver.switch_to.window(driver.window_handles[0])   

pyautogui.scroll(-10000)

pyautogui.moveTo(x=930, y=345)
pyautogui.click()

# -- Working Above
pyautogui.moveTo(x=1635, y=195)
pyautogui.click()

driver.switch_to.window(driver.window_handles[0])

pyautogui.moveTo(x=510, y=90)
pyautogui.click()

pyautogui.moveTo(x=1618, y=242)
pyautogui.click()

driver.switch_to.window(driver.window_handles[0])

# First Sleep
# After Cross
time.sleep(60)
print("hello ")

pyautogui.moveTo(x=1888, y=171)
pyautogui.click()

driver.switch_to.window(driver.window_handles[0])

pyautogui.moveTo(x=947, y=862)
pyautogui.click()

driver.switch_to.window(driver.window_handles[0])

pyautogui.scroll(-10000)
pyautogui.moveTo(x=935, y=275)
pyautogui.click()

driver.switch_to.window(driver.window_handles[0])


pyautogui.moveTo(x=1890, y=160)
pyautogui.click()

driver.switch_to.window(driver.window_handles[0])

pyautogui.moveTo(x=1890, y=110)
pyautogui.click()

driver.switch_to.window(driver.window_handles[0])

pyautogui.moveTo(x=1888, y=122)
pyautogui.click()

driver.switch_to.window(driver.window_handles[0])

pyautogui.moveTo(x=940, y=865)
pyautogui.click()

pyautogui.moveTo(x=940, y=820)
pyautogui.click()

driver.switch_to.window(driver.window_handles[0])

pyautogui.scroll(-10000)

pyautogui.moveTo(x=950, y=345)
pyautogui.click()

driver.switch_to.window(driver.window_handles[0])

pyautogui.moveTo(x=945, y=270)
pyautogui.click()

driver.switch_to.window(driver.window_handles[0])

# Second Sleep
time.sleep(12)

pyautogui.scroll(-10000)

pyautogui.moveTo(x=955, y=285)
pyautogui.click()

driver.switch_to.window(driver.window_handles[0])

# 5 (x=930, y=210)

pyautogui.moveTo(x=930, y=210)
pyautogui.click()

driver.switch_to.window(driver.window_handles[0])

pyautogui.moveTo(x=930, y=210)
pyautogui.click()

driver.switch_to.window(driver.window_handles[0])

pyautogui.moveTo(x=930, y=210)
pyautogui.click()

driver.switch_to.window(driver.window_handles[0])

pyautogui.moveTo(x=930, y=210)
pyautogui.click()

driver.switch_to.window(driver.window_handles[0])

pyautogui.moveTo(x=930, y=210)
pyautogui.click()

driver.switch_to.window(driver.window_handles[0])

# 5 (x=955, y=285)

pyautogui.moveTo(x=955, y=285)
pyautogui.click()

driver.switch_to.window(driver.window_handles[0])

pyautogui.moveTo(x=955, y=285)
pyautogui.click()

driver.switch_to.window(driver.window_handles[0])

pyautogui.moveTo(x=955, y=285)
pyautogui.click()

driver.switch_to.window(driver.window_handles[0])

pyautogui.moveTo(x=955, y=285)
pyautogui.click()

driver.switch_to.window(driver.window_handles[0])

pyautogui.moveTo(x=955, y=285)
pyautogui.click()

# Done

driver.switch_to.window(driver.window_handles[0])

pyautogui.scroll(-10000)

pyautogui.scroll(-10000)
pyautogui.moveTo(x=955, y=212)
pyautogui.click()

driver.switch_to.window(driver.window_handles[0])

pyautogui.scroll(-10000)
pyautogui.moveTo(x=955, y=212)
pyautogui.click()

driver.switch_to.window(driver.window_handles[0])

pyautogui.scroll(-10000)
pyautogui.moveTo(x=955, y=212)
pyautogui.click()

driver.switch_to.window(driver.window_handles[0])

pyautogui.scroll(-10000)
pyautogui.moveTo(x=955, y=212)
pyautogui.click()

driver.switch_to.window(driver.window_handles[0])


# Third Sleep
time.sleep(20)

pyautogui.moveTo(x=950, y=260)
pyautogui.click()

driver.switch_to.window(driver.window_handles[0])

pyautogui.moveTo(x=950, y=220)
pyautogui.click()

driver.switch_to.window(driver.window_handles[0])

pyautogui.moveTo(x=950, y=220)
pyautogui.click()

driver.switch_to.window(driver.window_handles[0])

pyautogui.moveTo(x=950, y=220)
pyautogui.click()

driver.switch_to.window(driver.window_handles[0])

pyautogui.moveTo(x=950, y=270)
pyautogui.click()

driver.switch_to.window(driver.window_handles[0])

pyautogui.scroll(-10000)
pyautogui.moveTo(x=937, y=270)
pyautogui.click()

driver.switch_to.window(driver.window_handles[0])






