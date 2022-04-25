01. ls – The most frequently used command in Linux to list directories
02. pwd – Print working directory command in Linux
03. cd – Linux command to navigate through directories
04. mkdir – Command used to create directories in Linux
05. mv – Move or rename files in Linux
06. cp – Similar usage as mv but for copying files in Linux
07. rm – Delete files or directories
07. touch – Create blank/empty files
07. ln – Create symbolic links (shortcuts) to other Files or Folder

In Linux:
ln -s /src_file.txt /result.txt
This result of "ln" command will work only in windows

In windows:
We can not create symbolic link as it will work only in windows
But for windows we can use command link this:
mklink result.txt src_file.txt

08. cat – Display file contents on the terminal
09. clear – Clear the terminal display
10. echo – Print any text that follows the command or write text inside the file
11. less – Linux command to display paged outputs in organized manner in the terminal
12. man – Access manual pages for all Linux commands
13. uname – Linux command to get basic information about the OS
14. whoami – Get the active username
15. tar – Command to extract and compress files in Linux
16. grep – Search for a string within an output
17. head – Return the specified number of lines from the top
18. tail – Return the specified number of lines from the bottom
19. diff – Find the difference between two files
20. cmp – Allows you to check if two files are identical
21. comm – Combines the functionality of diff and cmp
22. sort – Linux command to sort the content of a file while outputting
23. export – Export environment variables in Linux
24. zip – Zip files in Linux
25. unzip – Unzip files in Linux
25. ssh – Secure Shell command in Linux
26. service – Linux command to start and stop services
27. ps – Display active processes
28. kill and killall – Kill active processes by process ID or name
29. df – Display disk filesystem information
30. mount – Mount file systems in Linux
31. chmod – Command to change file permissions
32. chown – Command for granting ownership of files or folders
33. ifconfig – Display network interfaces and IP addresses
34. traceroute – Trace all the network hops to reach the destination
35. wget – Direct download files from the internet
36. ufw – Firewall command
37. iptables – Base firewall for all other firewall utilities to interface with
38. apt, pacman, yum, rpm – Package managers depending on the distro
39. sudo – Command to escalate privileges in Linux
40. cal – View a command-line calendar
41. alias – Create custom shortcuts for your regularly used commands
42. dd – Majorly used for creating bootable USB sticks
43. whereis – Locate the binary, source, and manual pages for a command
44. whatis – Find what a command is used for
45. top – View active processes live with their system usage
46. useradd and usermod – Add new user or change existing users data
47. passwd – Create or update passwords for existing users
48. ls -1 | wc -l --Command to get the count of the files present into directory.
49. kill --Command to kill the process (PID)
50. w -- to check how many users logged into the linux
51. date -- used to check the current date, time in linux
52. ls -a --List the hidden files in directory (hidden files are denatoed as ..)
53. ls -l --Use to check the permissions on all the files
54. ls -R -- used to list information about files and directories within the file system.
55. rm -rf -- remove directory with the files

su => 
Become root/super user 
[ no longer asks passwords again and again for applications installations ]

su - shank =>
Become normal user 

passwd =>
reset root/super user password

sudo passwd tom =>
To change a password for user named tom in Ubuntu, type:

sudo passwd root =>
To change a password for root user on Ubuntu Linux, run:

# Delete User =>
sudo killall -u username
userdel -f username

# Question - What is the difference between adduser and useradd?
# Answer
# The commands adduser and useradd are used to create such Users. The main difference is that adduser sets up user folders, directories, and other necessary functions easily, whereas useradd creates a new user without adding the directories as mentioned above and settings.

Add User =>
sudo adduser new_username
or:
sudo useradd new_username

# IF
# To remove/delete a user, first you can use:
sudo userdel username
# ELSE
# Because of bug ,user home directory for the user account may not be deleted
# You can use this command to delete this :
sudo rm -r /home/username

# List All User
cut -d: -f1 /etc/passwd