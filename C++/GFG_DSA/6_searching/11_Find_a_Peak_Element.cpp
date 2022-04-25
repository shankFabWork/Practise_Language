#include <iostream>

using namespace std;

// Not smaller than neighbour
// 5 10 20 15 7
// neighbour of 20 -> 10,15
// neighbour of 10 -> 5,20
// neighbour of 15 -> 20,7
// neighbour of 5 -> 10

// I/P->
// 5 10 20 15 7

// comparing 
// 10 20 15
// out of these 20 is greater than it's neightbour
// O/P->
// 20

// I/P->
// 10 20 15 5 23 90 67
// O/P->
// 20 or 90

// I/P->
// 80 70 60 90
// O/P->
// 80 or 90

void Find_a_Peak_Element_one(int arr[],int n)
{
    // if there is only one element 
    // then it is called peak element
    // as hter is no neighbour
    if(n == 1)
    {
        cout<<arr[0]<<" ";
    }
    if(arr[0] > arr[1])
    {
        cout<<arr[0]<<" ";
    }
    if(arr[n-1] > arr[n-2])
    {
        cout<<arr[n-1]<<" ";
    }

    for(int i=1;i<n-1;i++)
    {
        if(arr[i] >= arr[i-1] && arr[i] >= arr[i+1])
        {
            cout<<arr[i]<<" ";
        }
    }

}

int Find_a_Peak_Element_two(int arr[], int n)
{
	int low = 0, high = n - 1;

		while(low <= high)
		{
			int mid = (low + high) / 2;

			if((mid == 0 || arr[mid - 1] <= arr[mid]) &&
				(mid == n - 1 || arr[mid + 1] <= arr[mid]))
				return arr[mid];
			if(mid > 0 && arr[mid - 1] >= arr[mid])
				high = mid -1;
			else
				low = mid + 1;
		}
	return -1;
}


int main()
{
    int arr[]={10,7,8,20,12};
    int n=sizeof(arr)/sizeof(int);

    Find_a_Peak_Element_one(arr,n);
    //Time Complexity -> O(n)
    //Space Complexity -> O(1)

    cout<<endl;

    // not able to understand this 
    // u may try or skip it or cram it
    // --> cram it
    cout<<Find_a_Peak_Element_two(arr,n);
    // it will find eitheer in the left ot in the right
    //Time Complexity -> O(n)
    //Space Complexity -> O(1)

    return 0;
}

    //Time Complexity -> 
    //Space Complexity -> 


