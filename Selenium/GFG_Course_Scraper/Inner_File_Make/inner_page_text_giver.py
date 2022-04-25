from bs4 import BeautifulSoup
import re 
import os

def file_maker(file_s_folder_location,file_parsed_arr):
    counter = 1
    for i in file_parsed_arr:
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

        
        new_file = open(os.path.join(file_s_folder_location,orignal_file_name_with_ext), "w")
        new_file.write("import java.util.*; \n\n")
        new_file.write("public class {}\n".format(orignal_file_name_without_ext))
        new_file.write("{\n")
        new_file.write("\tpublic static void main(String []args)\n")
        new_file.write("\t{\n\n")
        new_file.write("\t}\n")
        new_file.write("}")
        new_file.close()
        counter = counter+1


def file_parser(file_name):
    f_name=""
    for j in file_name:
        if(j.isalnum()):
            f_name+=j
        else:
            f_name+="_"
        
    new_f_name = ""
    new_f_name = re.sub(r"(___|__|_|\s)",'_',f_name)
    return new_f_name


def inner_file_make(file_s_folder_location,soup_content):
    all_content = soup.find_all("div",{"class":"panel-body"})

    final_file_arr = []
    for i in all_content:
        str = i.find("a").find("strong")
        if str != None:
            parsed_file_name = file_parser(str.contents[0])
            final_file_arr.append(parsed_file_name)

            # printer
            # final_file_full_path = os.path.join(file_s_folder_location,final_file_name)
            # print(final_file_name+" ----- "+final_file_full_path)
            # print()
            
    # print(final_file_arr)
    file_maker(file_s_folder_location,final_file_arr)



with open('main_data.html', 'r') as f:
    file_s_folder_location = 'D:\\Shashank_Personal_Data\\Practise Language\\Selenium\\GFG_Course_Scraper\\Inner_File_Make\\a'
    contents = f.read()
    soup = BeautifulSoup(contents, 'lxml')
    
    inner_file_make(file_s_folder_location,soup)
