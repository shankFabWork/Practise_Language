import pyperclip
import requests
import random
import string
import time
import sys
import re
import os


# Global Variables
mail_name = ""
mail_content = ""

API = 'https://www.1secmail.com/api/v1/'
domainList = ['1secmail.com', '1secmail.net', '1secmail.org']
domain = random.choice(domainList)

def banner():
    print(r'''
                         ''~``
                        ( o o )
+------------------.oooO--(_)--Oooo.------------------+
|                                                     |
|                    Mail Swipe                       |
|               [by Sameera Madushan]                 |
|                                                     |
|                    .oooO                            |
|                    (   )   Oooo.                    |
+---------------------\ (----(   )--------------------+
                       \_)    ) /
                             (_/
    ''')

def generateUserName():
    name = string.ascii_lowercase + string.digits
    username = ''.join(random.choice(name) for i in range(10))
    return username

def extract():
    getUserName = re.search(r'login=(.*)&',newMail).group(1)
    getDomain = re.search(r'domain=(.*)', newMail).group(1)
    return [getUserName, getDomain]

# Got this from https://stackoverflow.com/a/43952192/13276219
def print_statusline(msg: str):
    last_msg_length = len(print_statusline.last_msg) if hasattr(print_statusline, 'last_msg') else 0
    print(' ' * last_msg_length, end='\r')
    print(msg, end='\r')
    sys.stdout.flush()
    print_statusline.last_msg = msg

def deleteMail():
    url = 'https://www.1secmail.com/mailbox'
    data = {
        'action': 'deleteMailbox',
        'login': f'{extract()[0]}',
        'domain': f'{extract()[1]}'
    }

    print_statusline("Disposing your email address - " + mail + '\n')
    req = requests.post(url, data=data)

def checkMails():
    reqLink = f'{API}?action=getMessages&login={extract()[0]}&domain={extract()[1]}'
    req = requests.get(reqLink).json()
    length = len(req)
    if length == 0:
        print_statusline("Your mailbox is empty. Hold tight. Mailbox is refreshed automatically every 1 seconds.")
    else:
        idList = []
        for i in req:
            for k,v in i.items():
                if k == 'id':
                    mailId = v
                    idList.append(mailId)

        x = 'mails' if length > 1 else 'mail'
        print_statusline(f"You received {length} {x}. (Mailbox is refreshed automatically every 1 seconds.)")

        current_directory = os.getcwd()
        final_directory = os.path.join(current_directory, r'All Mails')
        if not os.path.exists(final_directory):
            os.makedirs(final_directory)

        for i in idList:
            msgRead = f'{API}?action=readMessage&login={extract()[0]}&domain={extract()[1]}&id={i}'
            req = requests.get(msgRead).json()
            for k,v in req.items():
                if k == 'from':
                    sender = v
                if k == 'subject':
                    subject = v
                if k == 'date':
                    date = v
                if k == 'textBody':
                    content = v

            mail_file_path = os.path.join(final_directory, f'1.txt')

            with open(mail_file_path,'w') as file:
                file.write("Sender: " + sender + '\n' + "To: " + mail + '\n' + "Subject: " + subject + '\n' + "Date: " + date + '\n' + "Content: " + content + '\n')
        file_address=final_directory = os.path.join(current_directory, r'All Mails',r'1.txt')
        print(file_address)
        f = open(file_address, "r")
        f.readline()
        f.readline()
        f.readline()
        f.readline()
        final_data = f.readline()
        final_data = final_data.split(":")[1]
        mail_content=final_data[1::]
        print(mail_content)
        exit()
banner()

prefix="joker_will_remain_king_"
userInput2 = input("\nEnter the name that you wish to use as your domain name: ")
userInput2 = prefix+userInput2
newMail = f"{API}?login={userInput2}&domain={domain}"
reqMail = requests.get(newMail)
mail = f"{extract()[0]}@{extract()[1]}"
mail_name=mail
print(mail_name)
pyperclip.copy(mail)
print("\nYour temporary email is " + mail + " (Email address copied to clipboard.)" +"\n")
print(f"---------------------------- | Inbox of {mail}| ----------------------------\n")
while True:
    checkMails()
    time.sleep(1)


