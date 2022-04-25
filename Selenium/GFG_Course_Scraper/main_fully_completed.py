import time
import pandas as pd # pip install pandas
# pip install selenium
from selenium import webdriver
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
from selenium.webdriver.common.by import By
from selenium.common.exceptions import TimeoutException
from bs4 import BeautifulSoup # pip install beautifulsoup4
from webdriver_manager.chrome import ChromeDriverManager
import requests
from bs4 import BeautifulSoup
import re
import os

driver = webdriver.Chrome(ChromeDriverManager().install())
driver.implicitly_wait(1)
driver.maximize_window()

###################################################################

def file_maker(file_s_folder_location,file_parsed_arr,counter):
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
        orignal_file_name_with_ext = "_{}_{}.java".format(counter[0],new_f_name)
        orignal_file_name_without_ext = "_{}_{}".format(counter[0],new_f_name)

        
        new_file = open(os.path.join(file_s_folder_location,orignal_file_name_with_ext), "w")
        new_file.write("import java.util.*; \n\n")
        new_file.write("public class {}\n".format(orignal_file_name_without_ext))
        new_file.write("{\n")
        new_file.write("\tpublic static void main(String []args)\n")
        new_file.write("\t{\n\n")
        new_file.write("\t}\n")
        new_file.write("}")
        new_file.close()
        counter[0] = counter[0]+1


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


def inner_file_make(file_s_folder_location,soup,counter):
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
    file_maker(file_s_folder_location,final_file_arr,counter)

###################################################################
###################################################################

def link_opener(base_folder_loc,folders_name_arr,links_arr):
    c = 0
    index = 1

    for i in links_arr:
        print("------------------------------------")
        print("-----"+folders_name_arr[c]+"-----")

        # base_folder_loc=os.getcwd()
        # fol_location = os.path.join(base_folder_loc,fol_name)
        # os.mkdir(fol_location)

        # File Maker requires folder path and soup
        parsed_folder_name = file_parser(folders_name_arr[c])
        file_s_folder_location = os.path.join(base_folder_loc,parsed_folder_name)

        # Switch Tab Handler
        # driver.execute_script("window.open('');")
        # driver.switch_to.window(driver.window_handles[idx])
        # driver.get(i)

        # html_content = driver.page_source
        # soup_content = BeautifulSoup(html_content, 'lxml')
        # inner_file_make(file_s_folder_location,soup_content)

        counter = [1]

        driver.execute_script("window.open('');")
        driver.switch_to.window(driver.window_handles[index])
        index=index+1
        driver.get(i)

        html_content = driver.page_source
        soup_content = BeautifulSoup(html_content, 'lxml')
        data = soup_content.find("ul",{"class":"pagination"})
        inner_file_make(file_s_folder_location,soup_content,counter) 

        try:
            all_pages_url = []

            li_len = len(data.find_all("li"))
            for i in data.find_all("li")[1:li_len]:
                partial_url = (i.find("a")['href'] )
                full_url = "https://practice.geeksforgeeks.org/"+partial_url
                # print(full_url)
                all_pages_url.append(full_url)

            # print(all_pages_url)
            for data in all_pages_url[1:len(all_pages_url)-1]:
                driver.execute_script("window.open('');")
                driver.switch_to.window(driver.window_handles[index])
                index=index+1
                driver.get(data)

                html_content = driver.page_source
                soup_content = BeautifulSoup(html_content, 'lxml')
                inner_file_make(file_s_folder_location,soup_content,counter)        

        except:
            pass


        c=c+1
        time.sleep(1)

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

def show_heading_with_link(soup,base_folder_loc):
    links_arr=[]
    folders_name_arr=[]
    panel_heading_data = soup.find_all("div",{"class":"assignment-list"})
    folder_counter = 1
    for all_content in panel_heading_data:
        if all_content.find_all("div",{"class":"panel-heading"})[0].find("span").contents[0].strip() == "Data Structures and Algorithms":
            all_data = all_content.find_all("a",{"class":"text-design"}, href=True)
            for obj in all_data:
                # print("-------")
                final_text = str(folder_counter)+"_"+obj.text.strip()
                final_link = obj['href'].strip()
                # print(final_text+" "+final_link)
                links_arr.append(final_link)
                folders_name_arr.append(file_parser(final_text))
                os.mkdir(os.path.join(base_folder_loc,file_parser(final_text)))
                folder_counter=folder_counter+1

    link_opener(base_folder_loc,folders_name_arr,links_arr)


def automatic_login_function(login_url,username,password,redirected_url,base_folder_loc):
    driver.get(login_url)

    driver.find_element_by_id("luser").send_keys(username)
    driver.find_element_by_id("password").send_keys(password)
    driver.find_element_by_class_name("signin-button").click()

    time.sleep(5)

    driver.get(redirected_url)
    driver.find_element_by_class_name("showTextJs").click()

    html_content = driver.page_source
    soup = BeautifulSoup(html_content, 'lxml')

    show_heading_with_link(soup,base_folder_loc)


login_url="https://auth.geeksforgeeks.org/?to=https://www.geeksforgeeks.org/"
redirected_url="https://practice.geeksforgeeks.org/batch/Amazon-Test-Series"
username="Shivamsky58@gmail.com"
password="Amazon@123"
base_folder_loc='D:\\Shashank_Personal_Data\\Practise Language\\Selenium\\GFG_Course_Scraper\\result'

automatic_login_function(login_url,username,password,redirected_url,base_folder_loc)



