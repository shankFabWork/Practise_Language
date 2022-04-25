import os

def recursive_dir_size(path):
    size = 0

    for x in os.listdir(path):
        if not os.path.isdir(os.path.join(path,x)):
            size += os.stat(os.path.join(path,x)).st_size
        else:
            size += recursive_dir_size(os.path.join(path,x))

    return size

# path = r"D:\\\Paid_Courses\\a\\Coding Ninjas - Data Structures and Algorithms - Java"
path = r"D:\\Paid_Courses\\a\\Coding Ninjas - Data Structures and Algorithms - Java\\@csalgo Telegram.pdf"
folder_tot_size=recursive_dir_size(path)
print(folder_tot_size)