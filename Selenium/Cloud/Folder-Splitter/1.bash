TESTSTRINGONE="shank sharma"
NEWTESTSTRING=${TESTSTRINGONE:1:3}
echo ${NEWTESTSTRING}


rclone ls sharmashankfab_mega: > shank.txt
while IFS= read -r line; do
    echo "${line:10}"
done < shank.txt

rclone copy "/c/Users/shank/Desktop/Sumeet Sir Pepcoding Uploader" sharmashankfab_mega:backup/gajar/muli