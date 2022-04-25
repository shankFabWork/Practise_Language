Bash User Password :
lassin@1

# Error :
# Malformed entry 50 in list file /etc/apt/sources.list (Component)
# The list of sources could not be read.
# Malformed entry 50 in list file /etc/apt/sources.list (Component)
# The list of sources could not be read.
# Solution :
# In this case line number is 91 
# just change it to line number where problem is occuring
sudo sed -i '91s/\(.*\)/#\1/' /etc/apt/sources.list

# Install LFS
sudo apt-get install git-lfs
git-lfs install

# Upload using LFS
git lfs migrate import --include="*.*"

# upload without saving files in local
git commit --allow-empty

ssh-keygen -t ed25519 -C "shankfabulous@gmail.com"

eval "$(ssh-agent -s)"
ssh-add ~/.ssh/id_ed25519
clip < ~/.ssh/id_ed25519.pub

git config --global user.name shankFabWork
git config --global user.email shankfabulous@gmail.com
git config -l


# Saving Password In Cache
git config --global credential.helper cache


# --------------------------------------------------------
# Get latest timestamp with date and time
timestamp=$( date +"%d-%m-%Y_%I:%M:%S %P" )
echo $timestamp
# 13-03-2022_05:10:22 pm

# If you want to get only latest branch
# 1) Checkout
git checkout --orphan latest_branch
# 2) Add all the files
git add -A
# 3) Commit the changes
git commit -am "$( date +"%d-%m-%Y_%I:%M:%S %P" )"
# 4) Delete the branch
git branch -D main
# 5) Rename the current branch to main
git branch -m main
# 6) Finally, force update your repository
git push -f origin main
# --------------------------------------------------------

# To disable warning like "LF will be replaced by CRLF"
git config --global core.safecrlf false

# You've added another git repository inside your current repository.
# Clones of the outer repository will not contain the contents of
# the embedded repository and will not know how to obtain it.
# If you meant to add a submodule, use:
Simply Remove .git folder from each subfolder

# if libsecret is available.
git config --global credential.helper libsecret

# if libsecret isn't available.
git config --global credential.helper

# Work with "personal access tokens" 
1) Go to this link: https://github.com/settings/tokens 
(Profile -> settings -> developers setting -> personal access tokens). 
(don't go to repository setting; it's your profile setting)
2) Generate a new token and copy-paste it somewhere safely.
3) Search for an application in your Windows OS, named Credential Manager → then Windows Credentials.
4) Search for github.com and edit the password with the token you have generated on GitHub. Now enjoy!

# Git Large File Storage (LFS) replaces large files such as 
# audio samples, videos, datasets, and graphics with text pointers 
# inside Git, while storing the file contents on a remote server 
# like GitHub.com or GitHub Enterprise.
sudo apt install git-lfs
git lfs install

###################################
git branch -M main

git add .
git commit -m "13-03-2022_12:38"
git remote add origin https://github.com/shankpersonaldata/shankpersonaldata.git
git push -u origin main

shankFabWork
shankfabulous@gmail.com
lassino1




git add -A
git commit -m "g"
git branch -M main
git remote add origin https://github.com/shankpersonaldata/shankpersonaldata.git
git push -u origin main


UserName - shankFabWork
Token Name - personal_access_token_1
Token Code - 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





# I removed the .git in that particular folder. 
# Then after I ran the command
git rm -rf --cached myuntrackedfolder
git add myuntrackedfolder 

git commit -m "Changed to standalone repo"

git rm -rf --cached "PureScript/3D-object-rendering-in-purescript/"
git add "PureScript/3D-object-rendering-in-purescript/"

git add "Data Science/Pepcoding Data Science"

sudo -H gedit /etc/apt/sources.list
sudoedit /etc/apt/sources.list
deb http://site.example.com/debian distribution component1 component2 component3
deb-src http://site.example.com/debian distribution component1 component2 component3
sudo apt-get update