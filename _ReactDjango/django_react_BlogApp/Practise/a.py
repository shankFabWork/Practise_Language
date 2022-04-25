import re
pattern = "[a-z]+@+(edu|gmail|hotmail)+\.+com"
user_input = "shank@gmail.com"
if(re.search(pattern,user_input)):
    print("valid")
else:
    print("not valid")