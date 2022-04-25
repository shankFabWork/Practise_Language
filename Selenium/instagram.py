from selenium import webdriver
from selenium.webdriver.common.keys import Keys
driver = webdriver.Chrome(executable_path="C:\EV_Files\ChromeDriver\chromedriver.exe")
driver.get("https://www.instagram.com/")
time.sleep(2)
# username = driver.find_element_by_name("username")
username = driver.find_element_by_xpath('/html/body/div[1]/section/main/article/div[2]/div[1]/div/form/div/div[1]/div/label/input')
# username = driver.find_element_by_class_name("_2hvTZ pexuQ zyHYP")
# username = driver.find_element_by_css_selector("._2hvTZ pexuQ zyHYP")

username.click()
username.send_keys("sharma_shank.fab")
password = driver.find_element_by_name("password")
password.send_keys("lassino1")
driver.find_element_by_xpath('//*[@id="loginForm"]/div/div[3]').click()  
