# import time
# from selenium import webdriver
# from selenium.webdriver.common.keys import Keys
# driver = webdriver.Chrome(executable_path="C:\EV_Files\ChromeDriver\chromedriver.exe")
# # driver.implicitly_wait(5)
# driver.maximize_window()
# driver.get("https://earnably.com/")



from selenium import webdriver
from selenium.webdriver.chrome.options import Options

chrome_options = Options()
chrome_options.add_experimental_option("debuggerAddress", "127.0.0.1:9222")
#Change chrome driver path accordingly
chrome_driver = "C:\Program Files\Google\Chrome\Application\chrome.exe"
driver = webdriver.Chrome(chrome_driver, chrome_options=chrome_options)
driver.maximize_window()
driver.get("https://www.facebook.com/")
username = driver.find_element_by_xpath('//*[@id="email"]')
print(username.is_displayed())
print(username.is_enabled())