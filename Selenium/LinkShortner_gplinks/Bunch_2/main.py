import time
import os
import pyautogui
import time
import threading
from selenium import webdriver
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.chrome.options import Options


from commmon_code import main_code

os.system('python "D:\Shashank_Personal_Data\Practise Language\Selenium\LinkShortner_gplinks\Bunch_2\commmon_code.py"')

link_arr = [
    "https://gplinks.co/Z6QNC1",
    "https://gplinks.co/q6c2K5",
    "https://gplinks.co/z8QN9y8",
    "https://gplinks.co/reUKEm",
    "https://gplinks.co/SYYhh"
]
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

    link_set = {}
    i=0
    for x in link_arr:
        link_set["l{}".format(i)] = threading.Thread(target=main_code, args=[link_arr[i]])
        link_set["l{}".format(i)].start()
        i = i+1

    for counter in range(0,len(link_arr)):
        link_set["l{}".format(counter)].join()


#     # Close VPN
    pyautogui.moveTo(x=650, y=990)
    pyautogui.click()
    time.sleep(2)
    pyautogui.moveTo(x=1670, y=760)
    pyautogui.click()
    time.sleep(3)
    pyautogui.moveTo(x=1830, y=390)
    pyautogui.click()






