import subprocess as sp
import os
from mega import Mega
import re

# os.system("taskkill /im MEGAcmdServer.exe")

# mega = Mega()
mega_name = "shank112213 sharma" 
mega_mail = "shankfabulous@gmail.com"
mega_password = "sdfsfdf"

folder_name=r"D:\\Shashank_Personal_Data\\Practise Language\\Selenium\\Cloud\\root"
folder_name =  os.path.normpath(folder_name)
# folder_name = os.path.abspath(folder_name)
# folder_name = folder_name.replace("\\","/")
print(folder_name)
# m = mega.login("shankfabulous@gmail.com", "seeusoon")
# m.upload(folder_name)

try:
    # For Sign Up
    os.system("mega-logout")
    output = sp.getoutput("mega-signup {} {} --name=\"{}\" ".format(mega_mail,mega_password,mega_name))
    print(output)
    print("j")
    # For Login    
    # Signup requires to be logout
    # os.system("mega-logout")
    # os.system("mega-login {} {}".format(mega_mail,mega_password))
    # print("Successfully Login")
except:
    print("Wrong Credentials")

