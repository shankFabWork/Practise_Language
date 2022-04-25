import os
from mega import Mega
import re
# mega = Mega()
os.system("taskkill /im MEGAcmdServer.exe")
    
mega_mail = "shankfabulous@gmail.com"
mega_password = "seeusoon"

folder_name=r"D:\\Shashank_Personal_Data\\Practise Language\\Selenium\\Cloud\\root"
folder_name =  os.path.normpath(folder_name)
# folder_name = os.path.abspath(folder_name)
# folder_name = folder_name.replace("\\","/")
print(folder_name)
# m = mega.login("shankfabulous@gmail.com", "seeusoon")
# m.upload(folder_name)

try:
    os.system("mega-login {} {}".format(mega_mail,mega_password))
    print("Successfully Login")
except:
    print("Wrong Credentials")

os.system("mega-put \"{}\" ".format(folder_name))

# mega-put "D:\Paid_Courses\a"
