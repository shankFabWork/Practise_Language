import time
import os
import pyautogui
import time
import threading
from selenium import webdriver
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.chrome.options import Options
from http_request_randomizer.requests.proxy.requestProxy import RequestProxy

req_proxy = RequestProxy() 
proxies = req_proxy.get_proxy_list() 

PROXY = proxies[0].get_address()
webdriver.DesiredCapabilities.CHROME['proxy']={
    "httpProxy":PROXY,
    "ftpProxy":PROXY,
    "sslProxy":PROXY,
    
    "proxyType":"MANUAL",
    
}
driver = webdriver.Chrome(executable_path="C:\EV_Files\ChromeDriver\chromedriver.exe")
driver.get('https://www.expressvpn.com/what-is-my-ip')
driver.close()