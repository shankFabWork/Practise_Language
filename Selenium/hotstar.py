# from selenium import webdriver
# from selenium.webdriver.common.keys import Keys

# driver = webdriver.Chrome(executable_path="C:\EV_Files\ChromeDriver\chromedriver.exe")
# driver.get("https://www.hotstar.com/in")
# driver.find_element_by_css_selector('#searchField').send_keys("hwllo")
# # driver.find_element_by_id("searchField").send_keys("Movies")
# # driver.find_element_by_xpath('/html/body/div[1]/div/div/div[1]/div[1]/div/div[2]/div/div[4]/input').send_keys('Movies')
# # driver.find_element_by_id("searchField").send_keys(Keys.ENTER)
# # driver.find_element_by_id("searchField").send_keys("Hello")
# # driver.find_element_by_xpath('//*[@id="app"]/div/div/div[1]/div[1]/div/div[2]/div/button').click()
# # driver.find_element_by_link_text("LOGIN")
# # driver.find_element_by_xpath('//*[@id="app"]/div/div/div[1]/div[1]/div/div[2]/div/div[4]/div[2]/div[1]/article/a/div[2]').click()
# # driver.find_element_by_id("searchField").click()
# # driver.find_element_by_class_name()

# from selenium import webdriver
# from selenium.webdriver.common.keys import keys
# from selenium.import.*

# from selenium import webdriver
# driver = webdriver.Chrome("C:\\Users\\Neha_Vaidya\\eclipse-workspace\\Selenium\\chromedriver_win32\\chromedriver.exe")
# driver.get("https://www.hotstar.com")

# from selenium import webdriver
# from selenium.webdriver.common.keys import Keys

# driver = webdriver.Chrome(executable_path="C:\EV_Files\ChromeDriver\chromedriver.exe")
# driver.get("https://www.hotstar.com")
# driver.find_element_by_xpath("/html/body/div[1]/div/div/div[1]/div[1]/div/div[2]/div/div[4]/input").click()
# driver.find_element_by_id("searchField").click()
# driver.find_element_by_css_selector(".searchField").click()

from selenium import webdriver
from selenium.webdriver.chrome.options import Options
from selenium.webdriver.common.action_chains import ActionChains
from selenium.webdriver.common.keys import Keys
import time

options = webdriver.ChromeOptions()
##options.add_argument('--disable-notifications')
options.add_experimental_option("useAutomationExtension", False)
options.add_experimental_option("excludeSwitches",["enable-automation"])


# driver = webdriver.Chrome("D:\chromedriver.exe", options = options)
driver = webdriver.Chrome("C:\EV_Files\ChromeDriver\chromedriver.exe")
action = ActionChains(driver)
driver.maximize_window()
driver.get("https://www.hotstar.com")
time.sleep(2)
driver.find_element_by_id("searchField").click()
driver.find_element_by_id("searchField").send_keys("baaghi 3")
driver.find_element_by_id("searchField").send_keys(Keys.ENTER)
time.sleep(2)
driver.find_element_by_xpath('//*[@id="app"]/div/div/div[1]/div[2]/div/div/div/div/div[2]/div[1]/div/div/article/a/div[2]/div[4]/div[2]') .send_keys(Keys.ENTER)

# driver.find_element_by_name("Baaghi 3").send_keys(Keys.ENTER)
# search-wrap
# driver.find_element_by_id("searchField").send_keys(Keys.ENTER)
