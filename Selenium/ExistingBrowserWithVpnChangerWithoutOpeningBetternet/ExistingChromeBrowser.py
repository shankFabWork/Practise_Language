
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

# import os
# cmd_command='python OpenChrome.py'
# os.system(cmd_command)

opts = Options()
opts.add_experimental_option("debuggerAddress","localhost:9788")
driver = webdriver.Chrome(executable_path="C:\EV_Files\ChromeDriver\chromedriver.exe",options=opts)
# driver.maximize_window()
driver.get("https://google.com")
# driver.find_element_by_link_text("Log In").click()
# driver.find_element_by_id("email").send_keys("sharmashankfab@gmail.com")
# driver.find_element_by_id("password").send_keys("lassino1")
# driver.find_element_by_id("submit").click()

# driver.get("https://www.javatpoint.com/")
# driver.get("https://www.w3schools.com/")
# chrome.exe --remote-debugging-port=9788 --user-data-dir="C:\EV_Files\ChromeExistingBrowser"
# import os
# os.popen('chrome.exe --remote-debugging-port=9788 --user-data-dir="C:\EV_Files\ChromeExistingBrowser" ')
