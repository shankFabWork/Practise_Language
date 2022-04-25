import os
# print(os.getcwd())
txt = os.getcwd()+"\\File_Structure_Sort\\unsorted.txt"
f = open(txt,"r")
arr=[]
for i in f.readlines():
    arr.append(i)
arr.sort()

'''
# for i in arr:
#     path_arr=i.split("/")
#     path_arr_len=len(path_arr)
#     print(path_arr[path_arr_len-1])
'''

print(arr)

'''
# ------------------ This code check whether path is file or a folder ------------------ 
lower_case_ext_arr={'rm', 'pub', 'cty', 'jar', 'wma', 'asp', 'inf', 'wpl', 'hqx', 'lit', 'arc', 'swp', 'vxd', 'pak', 'rar', 'xlt', 'key', 'chm', 'vob', 'ncf', 'reg', 'aif', 'fla', 'dir', 'exe', 'cpp', 'bat', 'odp', 'lnk', 'asp ', 'ani', '3gp', 'html', 'icns', 'fnt', 'bas', 'uue', 'nitf', 
'prn', 'wmv', 'zip', 'tga', 'mp3', 'cgi', 'doc', 'obd', 'cer', 'qbb', 'hex', '3dm', 'mar', 'cpl', 'css', 'jpg', 'lhz', 'ybk', 'mpg ', 'mpeg', 'xls', 'nlm', 'eml', 'pdf', 'grp', 'dev', 'odt', 'cmf', 'flv', 'api', 'cfg', 'cur', 'dmp', 'pst', 'ogg', 'ttf', '3g2', 'bud', 'dbf', 'mid', 'xhtml', 'psd', 'ppt', 'cfm', 'mdl', 'dot', 'pptx', 'qbw', 'wri', 'ffo', 'vbs', 'part', 'clp', 'lab', 'js', 'pol', 'apk', 'bfc', 'ht', 'xml', 'tmp', 'ini', 'doc ', 'mpa', 'rpm', 'sit', 'avi', 'ods', 'kbm', 'deb', 'msi', 'cwk', 'db ', 'jpeg', 'xlsx', 'dxf', 'pct', 'phtml', 'gz', 'kqp', 'ppd', 'emf', 'kdc', 'fsh', 'xif', 'dic', 'mp4', 'qif', 'ndx', 'com', 'log', 'asm', 'dao', 'sql', 'sys', 'cmd', 'tiff', 'xlr', 'wps', 'pm', 'wav', 'shtml', 'mkv', 'cbl', 'csv', 'tif ', 'gid', 'ost', 'wsz', 'bmp', 'eps', 'java', 'jpeg ', 'ds', 'lsp', 'ffl', 'smd', 'ai', 'mfm', 'ppk', 'vm', 'ace', 'txt', 'tar', 'dat', 'cab', 'swf', 'raw', 'pps', 'max', 'bak', 'pm4', 'icm', '3ds', 'kiz', 'iff', 'sh', 'h264', 'cgi ', 'pm6', 'pl', 'pdb', 'rsc', 'msg', 'tex', 'asc', 'pwl', 'arj', 'htm', 'xcf', 'sgml', 'maq', 'jsp', 'drv', 'htm ', 'pdr', 'cda', 'mdb', 'ps', 'ram', 'rdo', 'gif', 'dd', 'mpp', 'cdt', 'xsl', 'pm5', 'cfml', 'wpd', 'lg', 'py', 'art', 'eve', 'midi', 'bin', 'psp', 'scr', 'ocx', 'dwg', 'wsf', 'cbt', 'dun', 'pcl', 'icl', 'udf', 'pot', 'c', 'vbx', 'sav', 'class', 'hlp', 'lgo', 'mov', 'pm3', 'aspx', 'wmf', 'docx', 'eps2', 'rtf', 'qxd', 'bz2', 'mod', 'o', 'oft', 'mid ', 'wks ', 'php', 'nff', 'cat', 'tcw', 'obj', 'dll', 'pif', 'sea', 'svg', 'ico', 'rss', 'accdb', 'png', 'cws', 'mht', 'm4v'}

# Folder Path
# path_str="root/[DesireCourse.Net] Udemy - Spark and Python for Big Data with PySpark_3/[DesireCourse.Net] Udemy - Spark and Python for Big Data with PySpark/18. Bonus"
# File Path
path_str="root/[DesireCourse.Net] Udemy - Spark and Python for Big Data with PySpark_3/[DesireCourse.Net] Udemy - Spark and Python for Big Data with PySpark/11. Linear Regression/1.Linear Regression Theory and Reading.mp4"
# path_str="root/[DesireCourse.Net] Udemy - Spark and Python for Big Data with PySpark_3/[DesireCourse.Net] Udemy - Spark and Python for Big Data with PySpark/11. Linear Regression/1. Linear Regression Theory and Reading.mp4"

path_arr=path_str.split("/")
path_arr_len=len(path_arr)
# print(path_arr[path_arr_len-1])
path_splitted=path_arr[path_arr_len-1].split(".")
path_splitted_len=len(path_splitted)
ext_name = path_splitted[path_splitted_len-1]

# print(path_splitted_len)

is_file=True
if path_splitted_len == 1:
    is_file=False
    print("It is folder ")
else:
    if ext_name in lower_case_ext_arr:
        is_file=True
        print("It is file "+ext_name)
    else:
        is_file=False
        print("It is folder ")
    
#  ------------------------------------------------------------------------ 
'''
    

