# from selenium import webdriver
# driver = webdriver.Chrome(executable_path="C:\EV_Files\ChromeDriver\chromedriver.exe")

# Open google.com and print title of "google.com" site
# driver.get("https://www.google.com/")
# print(driver.title)
# print(driver.current_url)

# driver.get("https://www.hotstar.com/in")
# driver.find_element_by_id("searchField").send_keys("Movies")

# driver.get("https://www.instagram.com/")
# driver.find_element_by_class_name("_2hvTZ pexuQ zyHYP").click()
# driver.find_element_by_name("username").send_keys("sharma_shank.fab")
# driver.find_element_by_xpath('/html/body/div[1]/section/main/article/div[2]/div[1]/div/form/div/div[1]/div/label/input').send_keys("sharma_shank.fab")
# driver.get("https://www.google.com/")
# driver.find_element_by_name("q").send_keys(   "Work From Home Jobs")
# driver.find_element_by_name("btnK").click()

# driver.find_element_by_link_text("Gmail").click()
# driver.find_element_by_css_selector("#searchField").click()
# driver.quit()

from selenium import webdriver
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.common.action_chains import ActionChains
import time
import random
from random import randint
import os


def update_file():
    with open('hashtags.txt') as f:
        main_list=f.read().splitlines()

    return(main_list)

def format(num):
    x=num.replace(',','')
    num=int(x)
    if num>999 and num<=999999:
        x=num%1000
        y=num//1000
        return(str(y)+'.'+str(x)[0]+'K')
    elif num>999999:
        x=num%1000000
        y=num//1000000
        return (str(y) + '.' + str(x)[0] + ' M')
    else: return (num)



br=webdriver.Chrome(executable_path="C:\EV_Files\ChromeDriver\chromedriver.exe")

br.get('https://www.instagram.com/accounts/login/')
time.sleep(5)
br.find_element_by_name('username').send_keys('username')
br.find_element_by_name('password').send_keys('password',Keys.ENTER)