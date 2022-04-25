import os
import shutil

def recursive_dir_size(path):
    size = 0

    for x in os.listdir(path):
        if not os.path.isdir(os.path.join(path,x)):
            size += os.stat(os.path.join(path,x)).st_size
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

def Folder_Splitter_King(path,s_path,folder_chunk_size_in_bytes):
    tot_size = len(path.split("\\"))
    last_dir = path.split("\\")[tot_size-1]
    # n_f='\\'.join(path.split("\\")[tot_size-1])
    # print(n_f)

    # Folder Size
    folder_tot_size=recursive_dir_size(path)

    fcsinb = folder_chunk_size_in_bytes
    while(folder_tot_size != 0):
        dir_num = 1
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


        # Get the list of all files in directory tree at given path
        listOfFiles = getListOfFiles(path)
        # print(listOfFiles)

        # ----------------- Main Function -----------------
        for i in listOfFiles:
            temp_each_chunk_folder_size = 0
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

            try:
                each_file_size = recursive_dir_size(src_path)
                temp_each_chunk_folder_size += each_file_size
                if temp_each_chunk_folder_size < fcsinb:
                    shutil.copyfile(src_path, dest_path)
            
            # If source and destination are same
            except shutil.SameFileError:
                print("Source and destination represents the same file.")
            
            # If destination is a directory.
            except IsADirectoryError:
                print("Destination is a directory.")
            
            # If there is any permission issue
            except PermissionError:
                print("Permission denied.")
            
            # For other errors
            except:
                print("Error occurred while copying file.")


        print("Folder "+str(dir_num)+" with chunk size less than "+str(fcsinb)+" is copied successfully.")

path = r"D:\\Paid_Courses\\a\\Coding Ninjas - Data Structures and Algorithms - Java"
s_path=r"D:\\Shashank_Personal_Data\\Practise Language\\Selenium\\Cloud\\Folder Structure\\root"
# In MB
folder_chunk_size=500
# GB -> MB -> KB -> B
folder_chunk_size_in_bytes = folder_chunk_size*1024*1024
Folder_Splitter_King(path,s_path,folder_chunk_size_in_bytes)