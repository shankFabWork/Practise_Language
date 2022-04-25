import time
import pandas as pd # pip install pandas
# pip install selenium
from selenium import webdriver
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
from selenium.webdriver.common.by import By
from selenium.common.exceptions import TimeoutException
from bs4 import BeautifulSoup # pip install beautifulsoup4
from webdriver_manager.chrome import ChromeDriverManager
import requests
from bs4 import BeautifulSoup
import re
from selenium.webdriver.common.keys import Keys


driver = webdriver.Chrome(ChromeDriverManager().install())


def link_opener(default_url,link_arr):
    driver.get(default_url)

    idx=1
    for i in link_arr:
        driver.execute_script("window.open('');")
        driver.switch_to.window(driver.window_handles[idx])
        driver.get(i)
        idx=idx+1
        print(driver.title)
        time.sleep(1)

link_arr = [
    "https://practice.geeksforgeeks.org/tracks/fork-python/?batchId=119",
    "https://practice.geeksforgeeks.org/tracks/python-module-2/?batchId=119",
    "https://practice.geeksforgeeks.org/tracks/python-module-3/?batchId=119",
    "https://practice.geeksforgeeks.org/tracks/python-module-4/?batchId=119",
    "https://practice.geeksforgeeks.org/tracks/python-module-5/?batchId=119",
    "https://practice.geeksforgeeks.org/tracks/python-module-6/?batchId=119"
]
default_url = "https://www.geeksforgeeks.org/"

link_opener(default_url,link_arr)
