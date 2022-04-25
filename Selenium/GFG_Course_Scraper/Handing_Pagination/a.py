from bs4 import BeautifulSoup
import re 
import os

with open('work.html', 'r') as f:

    contents = f.read()
    soup = BeautifulSoup(contents, 'lxml')




    driver.execute_script("window.open('');")
    driver.switch_to.window(driver.window_handles[idx])
    idx = idx + 1
    driver.get(i)

    html_content = driver.page_source
    soup_content = BeautifulSoup(html_content, 'lxml')
    data = soup_content.find("ul",{"class":"pagination"})
    inner_file_make(file_s_folder_location,soup_content) 

    try:
        li_len = len(data.find_all("li"))
        all_pages_url = []

        for i in data.find_all("li")[1:li_len-1]:
            partial_url = (i.find("a")['href'] )
            full_url = "https://practice.geeksforgeeks.org/"+partial_url
            # print(full_url)
            all_pages_url.append(full_url)

        inner_file_make(file_s_folder_location,soup_content) 

        # print(all_pages_url)
        for data in all_pages_url[1:len(all_pages_url)-1]:
            driver.execute_script("window.open('');")
            driver.switch_to.window(driver.window_handles[idx])
            idx = idx + 1
            driver.get(data)

            html_content = driver.page_source
            soup_content = BeautifulSoup(html_content, 'lxml')
            inner_file_make(file_s_folder_location,soup_content)        

    except:
        pass