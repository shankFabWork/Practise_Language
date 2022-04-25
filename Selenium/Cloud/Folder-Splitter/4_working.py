import os
path = r"D:\\Paid_Courses\\a\\Coding Ninjas - Data Structures and Algorithms - Java"
tot_size = len(path.split("\\"))

last_dir = path.split("\\")[tot_size-1]
# n_f='\\'.join(path.split("\\")[tot_size-1])
# print(n_f)
s_path=r"D:\\Shashank_Personal_Data\\Practise Language\\Selenium\\Cloud\\Folder Structure\\root"

dir_num = 1
dir_name_with_num=os.path.join(s_path,last_dir+"_"+str(dir_num))
dir_name_without_num=os.path.join(s_path, os.path.join(last_dir+"_"+str(dir_num),last_dir) )
os.mkdir(dir_name_with_num)
os.mkdir(dir_name_without_num)
# print(dir_name_without_num)


folders = []
# r=root, d=directories, f = files
for r, d, f in os.walk(path):
    for folder in d:
        folders.append(os.path.join(r, folder))

for f in folders:
    f = r"{}".format(f)
    # print('\\'.join(f.split("\\")[tot_size-1::]))
    n_f='\\'.join(f.split("\\")[tot_size::])
    os.mkdir(os.path.join(dir_name_without_num,n_f))
