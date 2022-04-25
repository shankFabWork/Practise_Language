import re
import os
f = open("all_text.txt","r")
counter = 1
for i in f:
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
    # os.system("touch {}".format(orignal_file_name))

    new_file = open(orignal_file_name_with_ext, "w")
    new_file.write("import java.util.*; \n\n")
    new_file.write("public class {}\n".format(orignal_file_name_without_ext))
    new_file.write("{\n")
    new_file.write("\tpublic static void main(String []args)\n")
    new_file.write("\t{\n\n")
    new_file.write("\t}\n")
    new_file.write("}")
    new_file.close()
    counter = counter+1
f.close()

