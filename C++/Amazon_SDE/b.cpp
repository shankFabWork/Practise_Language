#include <iostream>
using namespace std;

int countsubarray(int array[], int n, int k)
{
	int count = 0;
	int i, j, mul;

	for (i = 0; i < n; i++) {
		if (array[i] <= k)
			count++;

		mul = array[i];

		for (j = i + 1; j < n; j++) {
			mul = mul * array[j];
			if (mul <= k)
				count++;
			else
				break;
		}
	}

	return count;
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int k;
    cin>>k;
	int count = countsubarray(arr, n, k);
	cout << count << "\n";
}



