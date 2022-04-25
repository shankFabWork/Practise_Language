import time
import os
import pyautogui
import time

from selenium import webdriver
from selenium.webdriver.common.keys import Keys
path="C:\EV_Files\ChromeDriver\chromedriver.exe"
chrome_options = webdriver.ChromeOptions()
chrome_options.add_argument("--disable-notifications")
chrome_options.add_argument("--disable-popup-blocking")
driver=webdriver.Chrome(path,chrome_options=chrome_options)
driver.implicitly_wait(5)
driver.maximize_window()
driver.get("https://gplinks.co/SYYhh")
time.sleep(5)

pyautogui.moveTo(x=935, y=875)
pyautogui.click()

pyautogui.keyDown('ctrl')  
pyautogui.keyDown('w')  
pyautogui.keyUp('w')    
pyautogui.keyUp('ctrl') 

pyautogui.scroll(-10000)


# time.sleep(10)

pyautogui.moveTo(x=930, y=275)
pyautogui.click()

pyautogui.moveTo(x=1565, y=230)
pyautogui.click()

pyautogui.keyDown('ctrl')  
pyautogui.keyDown('w')  
pyautogui.keyUp('w')    
pyautogui.keyUp('ctrl') 

# time.sleep(8)

# click cross
pyautogui.moveTo(x=1890, y=160)
pyautogui.click()

pyautogui.moveTo(x=935, y=875)
pyautogui.click()

pyautogui.keyDown('ctrl')  
pyautogui.keyDown('w')  
pyautogui.keyUp('w')    
pyautogui.keyUp('ctrl')  

pyautogui.scroll(-10000)

pyautogui.moveTo(x=940, y=280)
pyautogui.click()

pyautogui.keyDown('ctrl')  
pyautogui.keyDown('w')  
pyautogui.keyUp('w')    
pyautogui.keyUp('ctrl')  

# time.sleep(12)

pyautogui.scroll(-10000)

pyautogui.moveTo(x=940, y=210)
pyautogui.click()

pyautogui.keyDown('ctrl')  
pyautogui.keyDown('w')  
pyautogui.keyUp('w')    
pyautogui.keyUp('ctrl')  

pyautogui.moveTo(x=940, y=210)
pyautogui.click()

pyautogui.keyDown('ctrl')  
pyautogui.keyDown('w')  
pyautogui.keyUp('w')    
pyautogui.keyUp('ctrl')  

# time.sleep(10)

pyautogui.moveTo(x=940, y=210)
pyautogui.click()

pyautogui.keyDown('ctrl')  
pyautogui.keyDown('w')  
pyautogui.keyUp('w')    
pyautogui.keyUp('ctrl')  

pyautogui.moveTo(x=940, y=210)
pyautogui.click()

pyautogui.keyDown('ctrl')  
pyautogui.keyDown('w')  
pyautogui.keyUp('w')    
pyautogui.keyUp('ctrl')  

pyautogui.moveTo(x=940, y=210)
pyautogui.click()

pyautogui.keyDown('ctrl')  
pyautogui.keyDown('w')  
pyautogui.keyUp('w')    
pyautogui.keyUp('ctrl')  

pyautogui.scroll(-10000)

# time.sleep(10)

pyautogui.moveTo(x=930, y=275)
pyautogui.click()

pyautogui.moveTo(x=1565, y=230)
pyautogui.click()

pyautogui.keyDown('ctrl')  
pyautogui.keyDown('w')  
pyautogui.keyUp('w')    
pyautogui.keyUp('ctrl')  

# time.sleep(2)

# click cross
pyautogui.moveTo(x=1890, y=160)
pyautogui.click()

pyautogui.moveTo(x=935, y=875)
pyautogui.click()

pyautogui.keyDown('ctrl')  
pyautogui.keyDown('w')  
pyautogui.keyUp('w')    
pyautogui.keyUp('ctrl') 

pyautogui.scroll(-10000)


# pyautogui.moveTo(x=940, y=210)
pyautogui.moveTo(x=960, y=210)
pyautogui.click()

pyautogui.keyDown('ctrl')  
pyautogui.keyDown('w')  
pyautogui.keyUp('w')    
pyautogui.keyUp('ctrl') 

# pyautogui.moveTo(x=940, y=210)
pyautogui.moveTo(x=960, y=210)
pyautogui.click()

