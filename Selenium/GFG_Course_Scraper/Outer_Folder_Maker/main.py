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


with open('output.html', 'r') as f:

    contents = f.read()
    soup = BeautifulSoup(contents, 'lxml')


# all_data = soup.find_all("a",{"class":"text-design"}, href=True)
# for obj in all_data:
#     # print("-------")
#     final_text = obj.text.strip()
#     final_link = obj['href'].strip()
#     # print(final_link)
#     print(final_text)
    # print(final_text+" "+final_link)
    # print("-------")

