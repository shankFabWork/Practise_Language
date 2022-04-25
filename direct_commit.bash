rm -rf .git
rm -fr .git
find . -name ".git*" -exec rm -R {} \;

git config --global user.name shankFabWork
git config --global user.email shankfabulous@gmail.com
git config -l

# Precautions
use .gitignore and add note_modules in case of node related project
use .gitignore and add note_modules in case of django related project






# First time run this command
git add .

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


npm install rimraf -g
rimraf node_modules

git init
git add .
git commit -m "First Commit"
git config --global user.name shankFabWork
git config --global user.email shankfabulous@gmail.com
git branch -M main
git remote add origin https://github.com/shankFabWork/Practise_Language.git
git push -u origin main
