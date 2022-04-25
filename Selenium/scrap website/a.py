import requests
from bs4 import BeautifulSoup

# p_no = int(input())

f_url = "https://www.91mobiles.com/top-10-mobiles-below-10000-in-india"

r = requests.get(f_url)
soup = BeautifulSoup(r.text,"html.parser")
# print(soup)
# print(soup.prettify)

all_names = soup.find_all("div",{"class":"hover_blue_link "})
all_description = soup.find_all("div",{"class":"descPart1_35003"})
all_price = soup.find_all("div",{"class":"price"})

# print(all_names)
# print(all_description)
# print(all_price)
# for i in range(10):
#     print(all_names[i].text+" ----- "+all_description[i].text+" ----- "+all_price[i].text)
