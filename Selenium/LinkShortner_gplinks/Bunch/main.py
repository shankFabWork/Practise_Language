import time
import os
import pyautogui
import time
import threading
from selenium import webdriver
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.chrome.options import Options

def working1():
    os.system('python "D:\Shashank_Personal_Data\Practise Language\Selenium\LinkShortner_gplinks\Bunch\working1.py"')

def working2():
    os.system('python "D:\Shashank_Personal_Data\Practise Language\Selenium\LinkShortner_gplinks\Bunch\working2.py"')

def working3():
    os.system('python "D:\Shashank_Personal_Data\Practise Language\Selenium\LinkShortner_gplinks\Bunch\working3.py"')

def working4():
    os.system('python "D:\Shashank_Personal_Data\Practise Language\Selenium\LinkShortner_gplinks\Bunch\working4.py"')

def working5():
    os.system('python "D:\Shashank_Personal_Data\Practise Language\Selenium\LinkShortner_gplinks\Bunch\working5.py"')


for i in range(100):

    # Open VPN
    pyautogui.moveTo(x=650, y=990)
    pyautogui.click()
    time.sleep(2)
    pyautogui.moveTo(x=1670, y=760)
    pyautogui.click()
    time.sleep(3)
    pyautogui.moveTo(x=1830, y=390)
    pyautogui.click()

    t1 = threading.Thread(target=working1)
    t1.start()
    t2 = threading.Thread(target=working2)
    t2.start()
    t3 = threading.Thread(target=working3)
    t3.start()
    t4 = threading.Thread(target=working4)
    t4.start()
    t5 = threading.Thread(target=working5)
    t5.start()

    t1.join()
    t2.join()
    t3.join()
    t4.join()
    t5.join()

    # Close VPN
    pyautogui.moveTo(x=650, y=990)
    pyautogui.click()
    time.sleep(2)
    pyautogui.moveTo(x=1670, y=760)
    pyautogui.click()
    time.sleep(3)
    pyautogui.moveTo(x=1830, y=390)
    pyautogui.click()






