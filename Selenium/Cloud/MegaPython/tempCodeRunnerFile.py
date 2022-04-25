import os
from mega import Mega
import re
mega = Mega()
folder_name=r"D:\\Shashank_Personal_Data\\Practise Language\\Selenium\\Cloud\\root"
m = mega.login("shankfabulous@gmail.com", "seeusoon")
m.upload(full_path)