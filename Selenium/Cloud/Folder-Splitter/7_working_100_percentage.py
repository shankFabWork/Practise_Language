import os
import shutil
import sys

def get_counter(path):
    tot_size = len(path.split("\\"))
    last_dir = path.split("\\")[tot_size-1]
    # print(path)
    new_arr = path.split("\\")
    # print(new_arr)
    for i in range(0,100):
        try:
            new_arr.remove('')
        except:
            pass
    # print(new_arr)

    # print(last_dir)
    counter = 1
    for i in new_arr:
        if i != last_dir:
            counter=counter+1
    # print(counter)
    return counter
    

def recursive_dir_size(path):
    size = 0

    for x in os.listdir(path):
        if not os.path.isdir(os.path.join(path,x)):
            size += os.path.getsize(os.path.join(path,x))
        else:
            size += recursive_dir_size(os.path.join(path,x))
    return size


def getListOfFiles(dirName):
    # create a list of file and sub directories 
    # names in the given directory 
    listOfFile = os.listdir(dirName)
    allFiles = list()
    # Iterate over all the entries
    for entry in listOfFile:
        # Create full path
        fullPath = os.path.join(dirName, entry)
        # If entry is a directory then get the list of files in this directory 
        if os.path.isdir(fullPath):
            allFiles = allFiles + getListOfFiles(fullPath)
        else:
            allFiles.append(fullPath)
                
    return allFiles


def Empty_Folder_Creater(path,s_path,dir_num):
    tot_size = len(path.split("\\"))
    last_dir = path.split("\\")[tot_size-1]
    # n_f='\\'.join(path.split("\\")[tot_size-1])
    # print(n_f)

    # Folder Size
    folder_tot_size=recursive_dir_size(path)

    fcsinb = folder_chunk_size_in_bytes
    dir_name_with_num=os.path.join(s_path,last_dir+"_"+str(dir_num))
    dir_name_without_num=os.path.join(s_path, os.path.join(last_dir+"_"+str(dir_num),last_dir) )
    try:
        os.mkdir(dir_name_with_num)
        os.mkdir(dir_name_without_num)
    except:
        pass
    # print(dir_name_without_num)


    folders = []
    # r=root, d=directories, f = files
    for r, d, f in os.walk(path):
        for folder in d:
            folders.append(os.path.join(r, folder))




    for f in folders:
        f = r"{}".format(f)
        # print('\\'.join(f.split("\\")[tot_size-1::]))
        # res='\\'.join(f.split("\\"))
        res=f.split("\\")
        for i in range(0,100):
            try:
                res.remove('')
            except:
                pass
        # print(res)
        # print(res[counter::])
        res='\\'.join(res[counter::])
        # os.mkdir(res)
        # print(res)
        try:
            os.mkdir(os.path.join(dir_name_without_num,res))
        except:
            pass
    return dir_name_without_num

def Folder_Splitter_King(path,s_path,folder_chunk_size_in_bytes,counter):
    folder_tot_size=recursive_dir_size(path)
    print("Total Source Folder Size is "+str(folder_tot_size))
    fcsinb = folder_chunk_size_in_bytes


    # Get the list of all files in directory tree at given path
    folder_number = 1
    dir_name_without_num = Empty_Folder_Creater(path,s_path,folder_number)
    temp_each_chunk_folder_size = 0
    # ----------------- Main Function -----------------
    listOfFiles = getListOfFiles(path)
    for i in listOfFiles:
        f = r"{}".format(i)
        res=f.split("\\")
        for i in range(0,100):
            try:
                res.remove('')
            except:
                pass
        # print(res[counter::])
        file_str = '\\'.join(res[counter::])
        # print(file_str)
        # print(os.path.join(path,file_str))
        # print(os.path.join(dir_name_without_num,file_str))
        src_path = r"{}".format(os.path.join(path,file_str))
        dest_path = r"{}".format(os.path.join(dir_name_without_num,file_str))

        each_file_size = os.path.getsize(src_path)
        try:
            if folder_tot_size >= 0:
                # current_folder_tot_size_1=recursive_dir_size(dir_name_without_num)
                # current_folder_tot_size_2=temp_each_chunk_folder_size+each_file_size

                if (recursive_dir_size(dir_name_without_num)+each_file_size) < fcsinb :
                # if temp_each_chunk_folder_size+each_file_size < fcsinb :

                    #Showing Status
                    # print(str(recursive_dir_size(dir_name_without_num)+each_file_size)+" "+str(folder_chunk_size_in_bytes))
                    shutil.copyfile(src_path, dest_path)
                    temp_each_chunk_folder_size = temp_each_chunk_folder_size+each_file_size
                else:
                    temp_each_chunk_folder_size = 0
                    print("Folder "+str(folder_number)+" with size "+str(recursive_dir_size(dir_name_without_num))+" with chunk size less than "+str(fcsinb)+" is copied successfully.")
                    folder_number = folder_number+1
                    dir_name_without_num = Empty_Folder_Creater(path,s_path,folder_number)
                    dest_path = r"{}".format(os.path.join(dir_name_without_num,file_str))
                    shutil.copyfile(src_path, dest_path)
                    temp_each_chunk_folder_size = temp_each_chunk_folder_size+each_file_size

                
        except shutil.SameFileError:
            print("Source and destination represents the same file.")
        except IsADirectoryError:
            print("Destination is a directory.")            
        except PermissionError:
            print("Permission denied.")
        except:
            print("Error occurred while copying file.")
        folder_tot_size = folder_tot_size - each_file_size


    print("Folder "+str(folder_number)+" with size "+str(recursive_dir_size(dir_name_without_num))+" with chunk size less than "+str(fcsinb)+" is copied successfully.")
    print(str(folder_tot_size)+" is left \n")
    print("Everything done successfully \n thank u")
    exit()

# User Reuired Only Three Input
# path = r"D:\\Paid_Courses\\a\\Coding Ninjas - Data Structures and Algorithms - Java"
path = r"D:\\Development__Courses\\Big Data\\[DesireCourse.Net] Udemy - Spark and Python for Big Data with PySpark"
s_path=r"D:\\Shashank_Personal_Data\\Practise Language\\Selenium\\Cloud\\root"
# In MB
folder_chunk_size=70


counter = get_counter(path)
# GB -> MB -> KB -> B
folder_chunk_size_in_bytes = folder_chunk_size*1024*1024

# Finding Maximun Folder  Size
listOfFiles = getListOfFiles(s_path)
max_file_size = 0
for i in listOfFiles:
    each_file_size = os.path.getsize(i)
    if max_file_size < each_file_size:
        max_file_size = each_file_size

print(str(max_file_size/(1024*1024))+" MB is the maximum file size")
print(str(folder_chunk_size_in_bytes/(1024*1024))+" MB is the file chunk size specified by user")

if max_file_size < folder_chunk_size_in_bytes:
    print("Yes you can split the file")
    Folder_Splitter_King(path,s_path,folder_chunk_size_in_bytes,counter)
    # pass
else:
    print("Please increase your chunk size greater than "+str(max_file_size/(1024*1024)))
    print("Current Chunk size specified by user is "+str(folder_chunk_size_in_bytes/(1024*1024)))

# for i in range(1,10):
#     print(Empty_Folder_Creater(path,s_path,i))