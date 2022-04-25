# import os
# mega_mail = "shankfabulous@gmail.com"
# mega_password = "seeusoon"

import os, re
output = os.popen('mega-ls -lr /').read()
lastfolder=""
all_folder_and_file_address=[]
for l in output.split("\n"):
    if len(l) and l[0] != '/':
        all_folder_and_file_address.append(lastfolder.strip(":")+"/"+" ".join(re.split(" +",l)[5:]))
    else:
        lastfolder=l.strip()   

for i in range(100):
    try:
        all_folder_and_file_address.remove("/") 
    except:
        pass

# Print all Files
# print(all_folder_and_file_address)
for i in all_folder_and_file_address:
    print(i+"\n")