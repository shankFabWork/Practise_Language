def upper_case_split(func):
    def inner(str):
        new_str=func(str)
        arr=new_str.split(" ")
        arr1=[]
        temp=""
        # for i in arr:
        #     temp=i[0].lower()+i[1:len(i)-1]+i[len(i)-1].lower()
        #     arr1.append(temp)
        #     temp=""
        # return arr1

        
        arr1 = [ i[0].lower()+i[1:len(i)-1]+i[len(i)-1].lower() for i in arr]
        print(arr1)
    return inner

@upper_case_split
def upper_case(str):
    return str.upper()

# upper_case_split=upper_case_split(upper_case)
print(upper_case("shank shamra"))
# str="shank shamra"
# print(str.upper())
