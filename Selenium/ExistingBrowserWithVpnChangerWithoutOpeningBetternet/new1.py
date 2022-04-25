import time
import os
import pyautogui
import time
import threading
from selenium import webdriver
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.chrome.options import Options

def escape_function():
    pyautogui.press('esc')  

for i in range(100):
    os.system("conda activate base")

    path="C:\EV_Files\ChromeDriver\chromedriver.exe"
    opts = Options()
    opts.add_extension("VPN_Master.crx")
    opts.add_argument("--disable-notifications")
    opts.add_argument("--disable-popup-blocking")
    driver = webdriver.Chrome(executable_path="C:\EV_Files\ChromeDriver\chromedriver.exe",options=opts)
    driver.maximize_window()


    # # Puzzle Icon
    # pyautogui.moveTo(1810,65)
    # pyautogui.click()
    # # Pin Icon
    # pyautogui.moveTo(1750,230)
    # pyautogui.click()
    # # Window Click
    # pyautogui.moveTo(1600,10)
    # pyautogui.click()
    # # Extension Icon
    # pyautogui.moveTo(1770,60)
    # pyautogui.click()
    # # Wait for 2 seconds
    # time.sleep(2)
    # # Connect Button
    # pyautogui.moveTo(1565,440)
    # pyautogui.click()
    # # Wait for 5 seconds
    # time.sleep(5)
    # # Window Click
    # pyautogui.moveTo(1600,10)
    # pyautogui.click()

    timer = threading.Timer(10.0, escape_function)
    driver.get("https://gplinks.co/Z6QNC1")
    timer.start()
    driver.implicitly_wait(1)



    # Open/Download
    try:
        driver.find_element_by_class_name("video-download").click()
    except:
        pass

    try:
        driver.switch_to.window(driver.window_handles[0])
        pyautogui.scroll(-1000)
        driver.implicitly_wait(1)
    except:
        pass

    try:
        pyautogui.scroll(-10000)
        driver.find_element_by_id("btn6").click()
        driver.switch_to.window(driver.window_handles[0])
    except:
        pass

    # Open/Download
    try:
        driver.find_element_by_class_name("video-download").click()
        driver.switch_to.window(driver.window_handles[0])
        pyautogui.scroll(-10000)
    except:
        pass

    # Open - Continue
    try:
        driver.find_element_by_id("btn6").click()
        driver.switch_to.window(driver.window_handles[0])
        pyautogui.scroll(-1000)
        time.sleep(15)
    except:
        pass

    pyautogui.scroll(-10000)

    #Unlock Link
    try:
        driver.find_element_by_id("unlock-btn").click()
        driver.switch_to.window(driver.window_handles[0])
        pyautogui.scroll(-1000)
    except:
        pass

    try:
        driver.find_element_by_id("unlock-btn").click()
        driver.switch_to.window(driver.window_handles[0])
        pyautogui.scroll(-1000)
    except:
        pass

    try:
        driver.find_element_by_id("unlock-btn").click()
        driver.switch_to.window(driver.window_handles[0])
        pyautogui.scroll(-1000)
        time.sleep(20)
    except:
        pass

    # Get Link
    try:
        driver.find_element_by_id("link-btn").click()
        driver.switch_to.window(driver.window_handles[0])
    except:
        pass

    driver.close()




