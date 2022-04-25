from selenium import webdriver
from selenium.webdriver.common.keys import Keys
from webdriver_manager.chrome import ChromeDriverManager

driver = webdriver.Chrome(ChromeDriverManager().install())

driver.implicitly_wait(5)
driver.maximize_window()
driver.get("https://mega.nz/register")
fname = driver.find_element_by_xpath('//*[@id="register-firstname-registerpage2"]')
fname.click()
fname.send_keys("joker")
lname = driver.find_element_by_xpath('//*[@id="register-lastname-registerpage2"]')
lname.click()
lname.send_keys("king")
mail_name = driver.find_element_by_xpath('//*[@id="register-email-registerpage2"]')
mail_name.click()
mail_name.send_keys("king")


# pyautogui.moveTo(x=940, y=865)
# pyautogui.click()

# driver.switch_to.window(driver.window_handles[0])   

# pyautogui.scroll(-10000)

# pyautogui.moveTo(x=930, y=345)
# pyautogui.click()

time.sleep(2)
driver.close()
