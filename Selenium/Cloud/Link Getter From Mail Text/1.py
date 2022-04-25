import re
myString = open("All Mails\\1.txt").read()
print(re.search("(?P<url>https?://[^\s]+)", myString).group("url"))