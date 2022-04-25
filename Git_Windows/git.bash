# Working with LFS
git lfs install
git lfs track '*.*'
git lfs push --all origin master
git push -u origin master


# Working with SSH Key
ssh-keygen -t ed25519 -C "shashankqainfotech@gmail.com"

eval "$(ssh-agent -s)"
ssh-add ~/.ssh/id_ed25519
clip < ~/.ssh/id_ed25519.pub

git config --global user.name shashankqainfotech
git config --global user.email shashankqainfotech@gmail.com

git remote add origin "https://github.com/shashankqainfotech/Assignment-Repo.git"
git push -u main

timestamp=$( date +"%d-%m-%Y_%I:%M:%S %P" )
git commit -am "$(timestamp)"