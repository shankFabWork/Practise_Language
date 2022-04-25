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

driver = webdriver.Chrome(ChromeDriverManager().install())

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

def link_opener(link_arr,text_arr):
    idx=1
    for i in link_arr:
        print("------------------------------------")
        print("-----"+text_arr[idx-1]+"-----")

        fol_name=file_parser(text_arr[idx-1])
        curr_folder_loc=os.getcwd()
        fol_location = os.path.join(curr_folder_loc,fol_name)
        os.mkdir(fol_location)

        driver.execute_script("window.open('');")
        driver.switch_to.window(driver.window_handles[idx])
        driver.get(i)
        idx=idx+1

        html_content = driver.page_source
        soup_content = BeautifulSoup(html_content, 'lxml')
        all_content = soup_content.find_all("div",{"class":"panel-body"})

        file_arr=[]
        for i in all_content:
            str = i.find("a").find("strong")
            if str != None:
                print(str.contents[0])
                file_arr.append(str.contents[0])
                
        print("------------------------------------")
        file_maker(os.path.join(fol_location,file_arr))

        time.sleep(1)

def automatic_login_function(login_url,username,password,redirected_url):
    driver.get(login_url)

    driver.find_element_by_id("luser").send_keys(username)
    driver.find_element_by_id("password").send_keys(password)
    driver.find_element_by_class_name("signin-button").click()

    time.sleep(5)

    driver.get(redirected_url)
    driver.find_element_by_class_name("showTextJs").click()

    html_content = driver.page_source
    soup = BeautifulSoup(html_content, 'lxml')

    # Show html output in "output.html"
    # with open("output.html", "w", encoding = 'utf-8') as file:
    #     file.write(str(soup_content.prettify()))

    links_arr=[]
    text_arr=[]
    panel_heading_data = soup.find_all("div",{"class":"assignment-list"})
    for all_content in panel_heading_data:
        if all_content.find_all("div",{"class":"panel-heading"})[0].find("span").contents[0].strip() == "Data Structures and Algorithms":

            all_data = all_content.find_all("a",{"class":"text-design"}, href=True)
            for obj in all_data:
                # print("-------")
                final_text = obj.text.strip()
                final_link = obj['href'].strip()


                links_arr.append(final_link)
                text_arr.append(final_text)

    try:
        link_opener(links_arr,text_arr)
    except:
        print("Scraping done")

login_url="https://auth.geeksforgeeks.org/?to=https://www.geeksforgeeks.org/"
redirected_url="https://practice.geeksforgeeks.org/batch/Amazon-Test-Series"
username="Shivamsky58@gmail.com"
password="Amazon@123"

automatic_login_function(login_url,username,password,redirected_url)