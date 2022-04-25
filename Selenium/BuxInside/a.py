from selenium import webdriver
from selenium.webdriver.common.keys import Keys
driver = webdriver.Chrome(executable_path="C:\EV_Files\ChromeDriver\chromedriver.exe")
driver.get("https://secure.buxinside.com/login")

email = driver.find_element_by_name("login_email")
email.click()
email.send_keys("sharmashankfab@gmail.com")
password = driver.find_element_by_name("login_password")
password.click()
password.send_keys("mBiHx8oK")

time.stop(5)

login_button = driver.find_element_by_name("Login2")
login_button.click()


# next_button = driver.find_element_by_xpath("/html/body/div[1]/div[3]/form/input")
# next_button.click()

