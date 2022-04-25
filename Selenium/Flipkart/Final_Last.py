import requests
from bs4 import BeautifulSoup

# p_no = int(input())

no_of_pages = 3
for p_no in range(no_of_pages):
    t_url = "https://www.flipkart.com/search?q=mobiles&as=on&as-show=on&otracker=AS_Query_TrendingAutoSuggest_1_0_na_na_na&otracker1=AS_Query_TrendingAutoSuggest_1_0_na_na_na&as-pos=1&as-type=TRENDING&suggestionId=mobiles&requestId=1a7e09d5-c15d-4d0b-8a62-914c104da368&page="
    f_url = t_url+str(p_no)

    r = requests.get(f_url)
    soup = BeautifulSoup(r.text,"html.parser")
    # print(soup)
    # print(soup.prettify)

    all_names = soup.find_all("div",{"class":"_4rR01T"})
    all_prices = soup.find_all("div",{"class":"_30jeq3 _1_WHN1"})

    print("######################################################")

    for i in range(len(all_names)):
        print(all_names[i].text+" ----- "+all_prices[i].text)

    if p_no == no_of_pages-1:
        print("######################################################")
