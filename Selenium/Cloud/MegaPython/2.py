import os
from mega import Mega
import re
# Kill MegaCmd May cause problem in upload
os.system("taskkill /im MEGAcmdServer.exe")
# folder_name=r"D:\\Shashank_Personal_Data\\Practise Language\\Selenium\\Cloud\\root"
# m = mega.login("shankfabulous@gmail.com", "seeusoon")
# m.upload(full_path)

user_password = {}
user_password["shankfabulous@gmail.com"] = "seeusoon"
user_password["sharmashankfab@gmail.com"] = "lassino1"




# mega = Mega()
folder_name="D:\\Shashank_Personal_Data\\Practise Language\\Selenium\\Cloud\\root"
# from os import listdir
# file_list = listdir(folder_name)
all_folder_name=(os.listdir(folder_name))
f_number = 0
for i,path in zip(user_password,os.listdir(folder_name)):

    # Get Folder Path
    full_path = os.path.join(folder_name, path)
    # if os.path.isdir(full_path):
    #     print(full_path)

    # Login and upload each Folder to each account respectively
    # print(i+" "+user_password[i])
    # m = mega.login(i, user_password[i])
    try:
        os.system("mega-login {} {}".format(i,user_password[i]))
        print("Successfully Login")
    except:
        print("Wrong Credentials")
    folder_name=r"{}".format(folder_name)
    if os.path.isdir(full_path):
        print(full_path)
        os.system("mega-put \"{}\" ".format(full_path))
        os.system("export -a \"{}\" ".format(full_path))
        

    # print(all_folder_name[f_number])
    # f_number = f_number+1

# import os
# for path in :


# Using Mega Python Library
