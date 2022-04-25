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
driver.get("https://gplinks.co/KBPqe")
time.sleep(5)

# from selenium.webdriver import ActionChains

# actions = ActionChains(driver)
# actions.double_click(element).perform()

import pyautogui
import time
# print(pyautogui.position())

# Iframe Box
pyautogui.moveTo(x=936, y=877)
pyautogui.click()


pyautogui.keyDown('ctrl')  
pyautogui.keyDown('w')  
pyautogui.keyUp('w')    
pyautogui.keyUp('ctrl')    

pyautogui.scroll(-10000)

pyautogui.moveTo(x=987, y=346)
pyautogui.click()

pyautogui.moveTo(x=1566, y=261)
pyautogui.click()

pyautogui.keyDown('ctrl')  
pyautogui.keyDown('w')  
pyautogui.keyUp('w')    
pyautogui.keyUp('ctrl')  

# # Click Cross
# pyautogui.moveTo(x=1888, y=175)
# pyautogui.click()

# # Iframe Box
# pyautogui.moveTo(x=961, y=884)
# pyautogui.click()

# pyautogui.keyDown('ctrl')  
# pyautogui.keyDown('w')  
# pyautogui.keyUp('w')    
# pyautogui.keyUp('ctrl')  

# pyautogui.scroll(-10000)

# pyautogui.moveTo(x=956, y=275)
# pyautogui.click()

# pyautogui.keyDown('ctrl')  
# pyautogui.keyDown('w')  
# pyautogui.keyUp('w')    
# pyautogui.keyUp('ctrl') 


# time.sleep(15)
# pyautogui.scroll(-10000)

# pyautogui.moveTo(x=949, y=233)
# pyautogui.click()

# pyautogui.keyDown('ctrl')  
# pyautogui.keyDown('w')  
# pyautogui.keyUp('w')    
# pyautogui.keyUp('ctrl') 

# pyautogui.keyDown('ctrl')  
# pyautogui.keyDown('w')  
# pyautogui.keyUp('w')    
# pyautogui.keyUp('ctrl') 

# pyautogui.keyDown('ctrl')  
# pyautogui.keyDown('w')  
# pyautogui.keyUp('w')    
# pyautogui.keyUp('ctrl') 

# pyautogui.keyDown('ctrl')  
# pyautogui.keyDown('w')  
# pyautogui.keyUp('w')    
# pyautogui.keyUp('ctrl') 

# pyautogui.keyDown('ctrl')  
# pyautogui.keyDown('w')  
# pyautogui.keyUp('w')    
# pyautogui.keyUp('ctrl') 

# pyautogui.scroll(-10000)

# pyautogui.moveTo(x=984, y=264)
# pyautogui.click()






