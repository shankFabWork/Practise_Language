from selenium import webdriver
from selenium.webdriver.common.keys import Keys
from webdriver_manager.chrome import ChromeDriverManager

password="lassino1"

driver = webdriver.Chrome(ChromeDriverManager().install())
driver.implicitly_wait(5)
driver.maximize_window()
# First Name
driver.get("https://mega.nz/register")
fname = driver.find_element_by_xpath('//*[@id="register-firstname-registerpage2"]')
fname.click()
fname.send_keys("joker")

# Last Name
lname = driver.find_element_by_xpath('//*[@id="register-lastname-registerpage2"]')
lname.click()
lname.send_keys("king")

# Mail
mail_name = driver.find_element_by_xpath('//*[@id="register-email-registerpage2"]')
mail_name.click()
mail_name.send_keys("shank@gmail.com")

# First Password
f_pass = driver.find_element_by_xpath('//*[@id="register-password-registerpage2"]')
f_pass.click()
f_pass.send_keys(password)
# Second Password
s_pass = driver.find_element_by_xpath('//*[@id="register-password-registerpage3"]')
s_pass.click()
s_pass.send_keys(password)
# First Checkbox
f_checkbox = driver.find_element_by_xpath('//*[@id="register_form"]/div[8]/div[1]/input')
f_checkbox.click()
# Second Password
s_checkbox = driver.find_element_by_xpath('//*[@id="register-check-registerpage2"]')
s_checkbox.click()
# Create Account
create_account = driver.find_element_by_xpath('//*[@id="register_form"]/button/span')
create_account.click()

body = driver.find_element_by_tag_name("body")
body.send_keys(Keys.CONTROL + 't')

driver.get("https://mega.nz/#confirmQ29uZmlybUNvZGVWMs2nK7X-BQAFFDjor__W2Gphcm9sZTQ5MjZAZG91d3guY29tCXNhZCBhc2Zk-QVXx7jqDYY")

create_account = driver.find_element_by_xpath('//*[@id="login-password2"]')
create_account.send_keys(password)

create_account = driver.find_element_by_xpath('//*[@id="login_form"]/button/span')
create_account.click()





# pyautogui.moveTo(x=940, y=865)
# pyautogui.click()

# driver.switch_to.window(driver.window_handles[0])   

# pyautogui.scroll(-10000)

# pyautogui.moveTo(x=930, y=345)
# pyautogui.click()

time.sleep(2)
driver.close()
