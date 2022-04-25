import time
from selenium import webdriver
from selenium.webdriver.common.keys import Keys
driver = webdriver.Chrome(executable_path="C:\EV_Files\ChromeDriver\chromedriver.exe")
driver.maximize_window()
driver.get("https://www.expedia.com/")
# time.sleep()
driver.find_element_by_class_name("uitk-tab-text").click()
# driver.find_elements_by_css_selector("#uitk-tab-text").click()
# time.sleep(2)
# driver.find_element_by_name("Study Music Alpha Waves: Relaxing Studying Music, Brain Power, Focus Concentration Music, ☯161")
# driver.find_element_by_class_name("yt-simple-endpoint style-scope ytd-video-renderer").click()


# uitk-tab-text