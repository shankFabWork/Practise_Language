import time
from selenium import webdriver
from selenium.webdriver.common.keys import Keys
driver = webdriver.Chrome(executable_path="C:\EV_Files\ChromeDriver\chromedriver.exe")
# driver.implicitly_wait(5)
driver.maximize_window()
driver.get("http://profitlink.info/Bw8")
# Close Pop Ups or Screen
# driver.find_element_by_class_name("pl-4b989b8a7a3c5b2863ba96ba462ed4b2__close").click()

# Go To Next Button
driver.find_element_by_id("invisibleCaptchaShortlink").click()
# driver.find_elements_by_partial_link_text("Go To Next Page").click()
# driver.find_element_by_name(" Get Link ").click()
time.sleep(20)
driver.find_element_by_xpath("/html/body/div[1]/div/div/div/div[2]/div/div/center[2]/p/button/a").click()
driver.find_element_by_name(" Get Link ").click()
driver.find_element_by_xpath("/html/body/div[1]/div/div/div/div[2]/div/div/center[2]/p/button/a").click()
# driver.find_elements_by_partial_link_text(link_text)
# driver.find_element_by_id("invisibleCaptchaShortlink").click()
# driver.find_element_by_id("invisibleCaptchaShortlink").click()
# driver.find_element_by_id("invisibleCaptchaShortlink").click()
# driver.find_element_by_id("invisibleCaptchaShortlink").click()
# driver.find_element_by_class_name("pl-4b989b8a7a3c5b2863ba96ba462ed4b2__close").click()
# driver.find_element_by_id("invisibleCaptchaShortlink").click()
# driver.find_element_by_xpath("/html/body/div[1]/div/div/div/div[2]/div/div/center[2]/p/button").click()
# driver.find_element_by_class_name("pl-4b989b8a7a3c5b2863ba96ba462ed4b2__close").click()

 

# next1 = driver.find_element_by_id("invisibleCaptchaShortlink").click()
# driver.find_element_by_name("Go To Next Page ").click()
# driver.find_element_by_name("Go To Next Page ").click()

# driver.find_element_by_name("Go To Next Page ").click()


# username = driver.find_element_by_xpath('//*[@id="email"]')
# print(username.is_displayed())
# print(username.is_enabled())
# username.click()
# username.send_keys("9318327164")
# password = driver.find_element_by_xpath('//*[@id="pass"]')
# password.send_keys("lassino1")
# driver.find_element_by_xpath("/html/body/div[1]/div[2]/div[1]/div/div/div/div[2]/div/div[1]/form/div[2]/button").click()  
