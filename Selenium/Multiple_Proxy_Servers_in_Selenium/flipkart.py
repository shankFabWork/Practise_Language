# import time
# import os
# from selenium import webdriver
# from selenium.webdriver.common.keys import Keys

# from selenium import webdriver
# from selenium.webdriver.opera.options import Options

# options = Options()
# options.binary_location = r'C:\Users\shank\AppData\Local\Programs\Opera\launcher.exe'
# driver = webdriver.Opera(options=options, executable_path=r'C:\EV_Files\OperaDriver\operadriver.exe')
# driver.get("http://google.com/")
# driver.get("https://www.flipkart.com/")
# driver.close()

# import time

# from selenium import webdriver
# from selenium.webdriver.chrome import service


# webdriver_service = service.Service(r'C:\EV_Files\OperaDriver\operadriver.exe')
# webdriver_service.start()

# driver = webdriver.Remote(webdriver_service.service_url, webdriver.DesiredCapabilities.OPERA)

# time.sleep(5)
# driver.get('https://www.google.com/')

# time.sleep(5) #see the result
# driver.quit()

# from selenium import webdriver
# from webdriver_manager.opera import OperaDriverManager

# driver = webdriver.Opera(executable_path=OperaDriverManager().install())

# driver.get("https://www.google.com")
# time.sleep(5) #see the result
# driver.quit()

# from selenium import webdriver
# from time import sleep

# # The profile where I enabled the VPN previously using the GUI.
# opera_profile = r'C:\\Users\\dan\\AppData\\Roaming\\Opera Software\\Opera Stable' 
# options = webdriver.ChromeOptions()
# options.add_argument('user-data-dir=' + opera_profile)
# options._binary_location = r'C:\Users\shank\AppData\Local\Programs\Opera\launcher.exe'
# driver = webdriver.Opera(executable_path=r'C:\EV_Files\OperaDriver\operadriver.exe',options=options)
# sleep(10)
# driver.get('https://whatismyipaddress.com')
# sleep(10)
# driver.quit()

# from selenium import webdriver

# driver=webdriver.Chrome(executable_path=r'C:\EV_Files\OperaDriver\operadriver.exe')

# driver.get('https://www.google.com/')



from selenium import webdriver
import time
from time import sleep

# Importing options for the Opera module
from selenium.webdriver.opera.options import Options



options = Options()
# Setting the location of the Opera Browser
options.binary_location = r'C:\Users\shank\AppData\Local\Programs\Opera\launcher.exe'
# Creation of Opera WebDriver instance
self.driver = webdriver.Opera(options=options, executable_path=r'C:\EV_Files\OperaDriver\operadriver.exe')

driver = self.driver
driver.get("https://duckduckgo.com/")
driver.maximize_window()



sleep(10)

# Close the browser.

