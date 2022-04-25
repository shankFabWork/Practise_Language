import time
from selenium import webdriver
from selenium.webdriver.common.keys import Keys
driver = webdriver.Chrome(executable_path="C:\EV_Files\ChromeDriver\chromedriver.exe")
driver.maximize_window()
driver.get("https://youtube.com/")
time.sleep(2)
driver.find_element_by_name('search_query').send_keys("study")
driver.find_element_by_name('search_query').send_keys(Keys.ENTER)
time.sleep(2)
driver.find_element_by_name("Study Music Alpha Waves: Relaxing Studying Music, Brain Power, Focus Concentration Music, ☯161")
driver.find_element_by_class_name("yt-simple-endpoint style-scope ytd-video-renderer").click()

# driver.find_element_by_xpath('//*[@id="search-icon-legacy"]/yt-icon').click()
# driver.find_element_by_id('//*[@id="search"]').click()
# driver.find_element_by_class_name('ytd-searchbox').click()
# driver.find_element_by_class_name('ytd-searchbox').send_keys("poco x3 pro")
# driver.find_element_by_class_name('ytd-searchbox').send_keys(Keys.ENTER)
# driver.find_element_by_xpath('//*[@id="search"]').send_keys("hello")
# driver.find_element_by_xpath('//*[@id="search-input"]').send_keys("python selenium")
# driver.find_element_by_xpath('//*[@id="search-input"]').send_keys(Keys.ENTER)
