#include <iostream>
#include <math.h>

using namespace std;

// ==> find sum of digit in a number
// I/P
// n = 253
// O/P
// 10
// 2+5+3
 
// ==> find sum of digit in a number
// I/P
// n = 9987
// O/P
// 33
// 9+9+8+7

// ==> find sum of digit in a number
// I/P
// n = 253
// O/P
// 10
// 2+5+3

int sum_of_digit(int no)
{
    if(no == 0)
    {
        return 0;
    }
    return (no%10)+sum_of_digit(no/10);
}

int maxCuts(int n, int a, int b, int c)
{
	if(n == 0)
		return 0;
	if(n <= -1)
		return -1;

	int res = max(maxCuts(n-a, a, b, c), 
	          max(maxCuts(n-b, a, b, c), 
	          maxCuts(n-c, a, b, c)));

	if(res == -1)
		return -1;

	return res + 1; 
}


void printSub(string str,string curr="",int index=0)
{
	if(index == str.length() )
	{
		cout<<curr<<" ";
		return;
	}
	printSub(str,curr,index+1);
	printSub(str,curr+str[index],index+1);
}

int main()
{
    int no=123;
    cout<<sum_of_digit(no);
    
    cout<<endl;
    cout<<maxCuts(5,2,1,5);

    cout<<endl;
    cout<<maxCuts(23,11,9,12);

    cout<<endl;
    string str="abc";
    printSub(str,"",0);

    return 0;
}