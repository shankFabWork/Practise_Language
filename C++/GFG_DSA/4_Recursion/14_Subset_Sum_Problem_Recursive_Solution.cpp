#include <iostream>

using namespace std;

// I/P
// arr[] = {10,5,2,3,6}
// sum = 8
// O/P
// 2

// I/P
// arr[] = {1,2,3}
// sum = 4
// O/P
// 1

// I/P
// arr[] = {10,20,15}
// sum = 37
// O/P
// 0

// I/P
// arr[] = {10,20,15}
// sum = 0
// O/P
// 1
// empty set is also a subset
// simply if sum = 0
// return 1

void subset_string(string str,string curr="",int index=0)
{
	if(index == str.length() )
	{
		cout<<curr<<" ";
		return;
	}
	subset_string(str,curr,index+1);
	subset_string(str,curr+str[index],index+1);
}

//if no of subset is 3 -> 2^3 => 8 leafes
//if no of subset is 4 -> 2^4 => 16 leafes

int subset_sum(int arr[],int n,int sum)
{
	if(n == 0)
	{
		return (sum == 0)?1:0;
	}
	return subset_sum(arr,n-1,sum) + subset_sum(arr,n-1,sum-arr[n-1]);
}

int main()
{

    subset_string("abc","",0);

	cout<<endl;

	int arr[]={10,20,15};
	int sum=25;
	int n=sizeof(arr)/sizeof(int);
	cout<<subset_sum(arr,n,sum);
	//  The time complexity is Theta(2^n)

    return 0;
}

