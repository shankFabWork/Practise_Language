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

    # Open VPN
    pyautogui.moveTo(x=650, y=990)
    pyautogui.click()
    time.sleep(2)
    pyautogui.moveTo(x=1670, y=760)
    pyautogui.click()
    time.sleep(3)
    pyautogui.moveTo(x=1830, y=390)
    pyautogui.click()


    path="C:\EV_Files\ChromeDriver\chromedriver.exe"
    chrome_options = webdriver.ChromeOptions()
    chrome_options.add_argument("--disable-notifications")
    chrome_options.add_argument("--disable-popup-blocking")
    opts = Options()
    # opts.add_experimental_option("debuggerAddress","localhost:9788")
    driver = webdriver.Chrome(executable_path=path,options=opts)
    driver.set_window_size(480, 320)
    driver.implicitly_wait(20)
    # driver.maximize_window()
    # driver.get("https://gplinks.co/KBPqe")
    driver.get("https://gplinks.co/Z6QNC1")



    timer = threading.Timer(5.0, escape_function)
    timer.start()

    # Open/Download
    try:
        driver.find_element_by_class_name("video-download").click()
    except:
        pass

    try:
        driver.switch_to.window(driver.window_handles[0])
        time.sleep(15)
    except:
        pass

    try:
        driver.find_element_by_id("btn6").click()
        driver.switch_to.window(driver.window_handles[0])
    except:
        pass

    # Open/Download
    try:
        driver.find_element_by_class_name("video-download").click()
        driver.switch_to.window(driver.window_handles[0])
    except:
        pass

    # Open - Continue
    try:
        driver.find_element_by_id("btn6").click()
        driver.switch_to.window(driver.window_handles[0])
        time.sleep(15)
    except:
        pass


    #Unlock Link
    try:
        driver.find_element_by_id("unlock-btn").click()
        driver.switch_to.window(driver.window_handles[0])
    except:
        pass

    try:
        driver.find_element_by_id("unlock-btn").click()
        driver.switch_to.window(driver.window_handles[0])
    except:
        pass

    try:
        driver.find_element_by_id("unlock-btn").click()
        driver.switch_to.window(driver.window_handles[0])
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

    # Close VPN
    pyautogui.moveTo(x=650, y=990)
    pyautogui.click()
    time.sleep(2)
    pyautogui.moveTo(x=1670, y=760)
    pyautogui.click()
    time.sleep(3)
    pyautogui.moveTo(x=1830, y=390)
    pyautogui.click()






