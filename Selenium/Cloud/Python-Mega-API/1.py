from mega import Mega
  
mega = Mega()
m = mega.login("sharmashankfab@gmail.com", "lassino1")

# filename = "Python-Mega-API//work.csv"
# m.upload(filename)

details = m.get_user()
print(details)

# FIND FILE
file = m.find('myfile.doc')

# THEN DOWNLOAD USING THE FILE OBJECT
m.download(file)
  
# DOWNLOAD FILE USING MEGA FILE URL
m.download_url()
  
# SPECIFY DOWNLOAD LOCATION
m.download(file, '/home/john-smith/Desktop')