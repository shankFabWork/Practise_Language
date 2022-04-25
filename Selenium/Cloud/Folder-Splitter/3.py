# path = r"D:\\Development__Courses\\Django\\Python Django 2021 - Complete Course\14 Class Based Views\002 Built in views.html"
# print(path)

import os

# path = r"D:\\Development__Courses\\Django\\Python Django 2021 - Complete Course"
path = r"D:\\Paid_Courses\\a\\Coding Ninjas - Data Structures and Algorithms - Java"
tot_size=len(path.split("\\"))
folders = []

# r=root, d=directories, f = files
for r, d, f in os.walk(path):
    for folder in d:
        folders.append(os.path.join(r, folder))

s_path=r"D:\\Shashank_Personal_Data\\Practise Language\\Selenium\\Cloud\\Folder Structure\\root"
for f in folders:
    f = r"{}".format(f)
    # print('\\'.join(f.split("\\")[tot_size-1::]))
    n_f='\\'.join(f.split("\\")[tot_size-3:tot_size-1:-1])
    # os.mkdir(os.path.join(s_path,n_f))
    print(n_f)

