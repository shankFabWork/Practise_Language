import time
import os
import pyautogui
import time
import threading
from selenium import webdriver
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.chrome.options import Options

def browser_task1():

    path="C:\EV_Files\ChromeDriver\chromedriver.exe"
    chrome_options = webdriver.ChromeOptions()
    chrome_options.add_argument("--disable-notifications")
    chrome_options.add_argument("--disable-popup-blocking")
    opts = Options()
    # opts.add_experimental_option("debuggerAddress","localhost:9788")
    driver1 = webdriver.Chrome(executable_path="C:\EV_Files\ChromeDriver\chromedriver.exe")
    driver1.implicitly_wait(20)
    driver1.maximize_window()
    # driver1.get("https://gplinks.co/KBPqe")
    driver1.get("https://gplinks.co/Z6QNC1")


    # Open/Download
    try:
        driver1.find_element_by_class_name("video-download").click()
    except:
        pass

    try:
        driver1.switch_to.window(driver1.window_handles[0])
        pyautogui.scroll(-1000)
        time.sleep(15)
    except:
        pass

    try:
        pyautogui.scroll(-10000)
        driver1.find_element_by_id("btn6").click()
        driver1.switch_to.window(driver1.window_handles[0])
    except:
        pass

    # Open/Download
    try:
        driver1.find_element_by_class_name("video-download").click()
        driver1.switch_to.window(driver1.window_handles[0])
        pyautogui.scroll(-10000)
    except:
        pass

    # Open - Continue
    try:
        driver1.find_element_by_id("btn6").click()
        driver1.switch_to.window(driver1.window_handles[0])
        pyautogui.scroll(-1000)
        time.sleep(15)
    except:
        pass

    pyautogui.scroll(-10000)

    #Unlock Link
    try:
        driver1.find_element_by_id("unlock-btn").click()
        driver1.switch_to.window(driver1.window_handles[0])
        pyautogui.scroll(-1000)
    except:
        pass

    try:
        driver1.find_element_by_id("unlock-btn").click()
        driver1.switch_to.window(driver1.window_handles[0])
        pyautogui.scroll(-1000)
    except:
        pass

    try:
        driver1.find_element_by_id("unlock-btn").click()
        driver1.switch_to.window(driver1.window_handles[0])
        pyautogui.scroll(-1000)
        time.sleep(20)
    except:
        pass

    # Get Link
    try:
        driver1.find_element_by_id("link-btn").click()
        driver1.switch_to.window(driver1.window_handles[0])
    except:
        pass

    driver1.close()

def browser_task2():

    path="C:\EV_Files\ChromeDriver\chromedriver.exe"
    chrome_options = webdriver.ChromeOptions()
    chrome_options.add_argument("--disable-notifications")
    chrome_options.add_argument("--disable-popup-blocking")
    opts = Options()
    # opts.add_experimental_option("debuggerAddress","localhost:9788")
    driver = webdriver.Chrome(executable_path="C:\EV_Files\ChromeDriver\chromedriver.exe")
    driver.implicitly_wait(20)
    driver.maximize_window()
    # driver.get("https://gplinks.co/KBPqe")
    driver.get("https://gplinks.co/Z6QNC1")


    # Open/Download
    try:
        driver.find_element_by_class_name("video-download").click()
    except:
        pass

    try:
        driver.switch_to.window(driver.window_handles[0])
        pyautogui.scroll(-1000)
        time.sleep(15)
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

    t1 = threading.Thread(target=browser_task1)
    t1.start()
    time.sleep(2)
    t2 = threading.Thread(target=browser_task2)
    t2.start()

    t1.join()
    t2.join()

    # Close VPN
    pyautogui.moveTo(x=650, y=990)
    pyautogui.click()
    time.sleep(2)
    pyautogui.moveTo(x=1670, y=760)
    pyautogui.click()
    time.sleep(3)
    pyautogui.moveTo(x=1830, y=390)
    pyautogui.click()






