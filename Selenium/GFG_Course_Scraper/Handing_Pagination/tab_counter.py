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
import os

driver = webdriver.Chrome(ChromeDriverManager().install())
driver.implicitly_wait(1)
driver.maximize_window()

driver.execute_script("window.open('');")
driver.execute_script("window.open('');")
driver.execute_script("window.open('');")
print(len(driver.window_handles))
# driver.switch_to.window(driver.window_handles[len(driver.window_handles)])
# driver.get(data)

# html_content = driver.page_source
# soup_content = BeautifulSoup(html_content, 'lxml')
# inner_file_make(file_s_folder_location,soup_content) 