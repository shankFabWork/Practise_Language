import os
# Remember to put double slash over here
# Also put double slash at the end
path = r"D:\\Development__Courses\\Django\\"
s_path = r"D:\\Shashank_Personal_Data\\Practise Language\\Selenium\\Cloud\\Folder Structure\\root\\"
str_length = len(path)

# print(str_length)

l = os.listdir(path)
# print(l)

file_path_size_dict = {}
# file size in bytes
for root,dirs,files in os.walk(path):
    for file in files:
        file_path = os.path.join(root,file)
        file_size = os.path.getsize(file_path)
        # print(file_path+" "+str(file_size))
        file_path_size_dict[file_path] = file_size

# print(file_path_size_dict)
for i in file_path_size_dict:
    print(r""+i+" - "+str(file_path_size_dict[i]))
# or


