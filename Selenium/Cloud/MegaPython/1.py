# !pip install mega.py

import os
from mega import Mega
import re

mega_mail = "shankfabulous@gmail.com"
mega_password = "seeusoon"

# Using Mega Python Library
mega = Mega()
m = mega.login(mega_mail, mega_password)

# get Quota
quota = m.get_quota()
print("Total Space: ", quota)

# Using mega-cmd Login
os.system("mega-login {} {}".format(mega_mail,mega_password))

# filename="D:\\Shashank_Personal_Data\\Hacks\\RClone\\rclone-v1.53.3-windows-amd64\\README.html"
# filename=r"{}".format(filename)
# m.upload(filename)


# Print All File List
import os, re
output = os.popen('mega-ls -lr /').read()
lastfolder=""
all_folder_and_file_address=[]
for l in output.split("\n"):
    if len(l) and l[0] != '/':
        all_folder_and_file_address.append(lastfolder.strip(":")+"/"+" ".join(re.split(" +",l)[5:]))
    else:
        lastfolder=l.strip()   


# Print All File List with Mega Link
output = os.popen('mega-ls -lr').read()
lastfolder=""
file_with_size={}

for l in output.split("\n"):
    if len(l) and l[0] != '/':
        each_file_name = (lastfolder.strip(":")+"/"+" ".join(re.split(" +",l)[5:]))
        file_splitter_arr = each_file_name.split("/")
        # print(file_splitter_arr)
        clean_each_file_name = (file_splitter_arr[len(file_splitter_arr)-1])
        try:
            f_name = m.find(clean_each_file_name)
            res_link = m.get_link(f_name)
            print(clean_each_file_name+"\n"+res_link)
            print()
            file_with_size[each_file_name]=res_link
        except:
            # print(clean_each_file_name+" this is folder")
            pass
    else:
        lastfolder=l.strip()

print(file_with_size)


# Using mega-cmd Login
os.system("mega-logout")