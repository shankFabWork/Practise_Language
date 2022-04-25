import re
import os

def file_maker(curr_folder_loc,arr):
    counter = 1
    for i in arr:
        f_name=""
        for j in i:
            if(j.isalnum()):
                f_name+=j
            else:
                f_name+="_"
            
        new_f_name = ""
        new_f_name = re.sub(r"(___|__|_|\s)",'_',f_name)

        if new_f_name[len(new_f_name)-1] == "_":
            new_f_name = new_f_name[0:len(new_f_name)-1]
        orignal_file_name_with_ext = "_{}_{}.java".format(counter,new_f_name)
        orignal_file_name_without_ext = "_{}_{}".format(counter,new_f_name)

        
        new_file = open(os.path.join(curr_folder_loc,orignal_file_name_with_ext), "w")
        new_file.write("import java.util.*; \n\n")
        new_file.write("public class {}\n".format(orignal_file_name_without_ext))
        new_file.write("{\n")
        new_file.write("\tpublic static void main(String []args)\n")
        new_file.write("\t{\n\n")
        new_file.write("\t}\n")
        new_file.write("}")
        new_file.close()
        counter = counter+1


# curr_folder_loc='D:\\Shashank_Personal_Data\\Practise Language\\Selenium'
curr_folder_loc=os.getcwd()
arr=["Count number of hops","0 - 1 Knapsack Problem","Coin Change - Minimum number of coins","Maximize The Cut Segments","Wildcard Pattern Matching"]
file_maker(curr_folder_loc,arr)