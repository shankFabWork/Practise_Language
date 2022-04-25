# s_path="/mnt/d/Development__Courses/Django/Python Django 2021 - Complete Course"
# for entry in "$search_dir"/*
# do
#   echo "$entry"
# done

# d_path="/mnt/d/Shashank_Personal_Data/Practise Language/Selenium/Cloud/Folder Structure/root"

# s_path="/mnt/d/Development__Courses/Django/Python Django 2021 - Complete Course"
# ls "$s_path" > output_file.txt
# ls "$s_path" | grep * > output_file.txt
f="/mnt/d/Paid_Courses/a/Coding Ninjas - Data Structures and Algorithms - Java"
FOLDER=(`ls ${f}`)
echo ${FOLDER[1]}