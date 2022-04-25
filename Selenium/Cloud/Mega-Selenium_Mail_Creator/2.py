# Login in Mega
import os
from mega import Mega
import re
os.system("taskkill /im MEGAcmdServer.exe")

mega_name = "shank112213 sharma" 
mega_mail = "shankfabulous@gmail.com"
mega_password = "adsdsadsd"
# os.system("mega-login {} {}".format(mega_mail,mega_password))
# os.system("mega-login {} {}".format(mega_mail,mega_password))

#Signup requires to be logout
os.system("mega-logout")
# try:
#     os.system("mega-signup {} {} --name=\"{}\" ".format(mega_mail,mega_password,mega_name))
#     print("mail created successfully")
# except:
#     print("mail already exist")