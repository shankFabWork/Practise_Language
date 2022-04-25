


# Opening Chrome Browser at port 9788
# import os
# cmd_command='chrome.exe --remote-debugging-port=9788 --user-data-dir="C:\EV_Files\ChromeExistingBrowser"'
# os.system(cmd_command)
# python OpenChrome.py

#Opening new terminal with pynput
# Final Key To Press "ctrl+shift+`"
# from pynput.keyboard import Key, Controller
# keyboard = Controller()
# keyboard.press(Key.ctrl)
# keyboard.press(Key.shift)
# keyboard.press("`")
# keyboard.release(Key.ctrl)
# keyboard.release(Key.shift)
# keyboard.release("`")
# from pynput.keyboard import Key, Controller
# keyboard = Controller()
# keyboard.press(Key.ctrl)
# keyboard.press(Key.shift)
# keyboard.press("p")
# keyboard.release(Key.ctrl)
# keyboard.release(Key.shift)
# keyboard.release("p")

# Working on existing browser in selenium
from selenium import webdriver
from selenium.webdriver.chrome.options import Options

opts = Options()
opts.add_experimental_option("debuggerAddress","localhost:9788")
driver = webdriver.Chrome(executable_path="C:\EV_Files\ChromeDriver\chromedriver.exe",options=opts)
# driver.maximize_window()
driver.implicitly_wait(4)

driver.get("https://earnably.com/earn/videos")

# driver.find_element_by_link_text("Log In").click()
try:
    driver.find_element_by_id("email").send_keys("sharmashankfab@gmail.com")
    driver.find_element_by_id("password").send_keys("lassino1")
    driver.find_element_by_id("submit").click()
except:
    print("already login")

driver.execute_script('window.open("https://adscendmedia.com/adwall/publisher/32320/new/profile/13180?subid1=1622617")')
driver.find_element_by_xpath('//*[@id="Brid_92783923"]/div/div[5]/span/svg/path[3]').click()

# driver.switch_to.window(driver.window_handles[1])
# driver.close()
driver.find_element_by_class_name("aw_offerlink btn-points").click()

# driver.get("https://hideout.co/login.php")
# driver.find_element_by_id("username").send_keys("sharmashankfab@gmail.com")
# driver.find_element_by_id("password").send_keys("lassino1")
# driver.find_element_by_xpath('//*[@id="login"]/div[4]/button').click()
# driver.find_element_by_class_name("videoname_linkdiv").click()
# driver.find_element_by_xpath('//*[@id="comments-container"]/div[1]/div[2]/div[1]').click()
# driver.find_element_by_xpath('//*[@id="comments-container"]/div[1]/div[2]/div[1]').send_keys("good work")
# driver.find_element_by_xpath('//*[@id="comments-container"]/div[1]/div[2]/div[2]/span').send_keys("good work")
# driver.get("https://www.javatpoint.com/")
# driver.get("https://www.w3schools.com/")
# chrome.exe --remote-debugging-port=9788 --user-data-dir="C:\EV_Files\ChromeExistingBrowser"
# import os
# os.popen('chrome.exe --remote-debugging-port=9788 --user-data-dir="C:\EV_Files\ChromeExistingBrowser" ')
