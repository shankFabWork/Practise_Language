import re
# s = "Arrays and Strings"
# ans = re.sub(r'[^\d|\w|\'|\s|$|\.]', ' ', s)
# print(ans)

file_name = "Dynamic Programming"
f_name=""
for j in file_name:
    if(j.isalnum()):
        f_name+=j
    else:
        f_name+="_"
    
new_f_name = ""
new_f_name = re.sub(r"(___|__|_|\s)",'_',f_name)
print(new_f_name)


# f = open("demofile3.txt", "w")
# f.write("import java.util.*; \n\n")
# f.write("public class check_if_number_is_prime\n")
# f.write("{\n")
# f.write("\tpublic static void main(String []args)\n")
# f.write("\t{\n\n")
# f.write("\t}\n")
# f.write("}")
# f.close()