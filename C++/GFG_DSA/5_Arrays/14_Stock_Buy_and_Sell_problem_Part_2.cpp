// assumption : we already know that the profit 
// and loss prices in stock 
// you will only buy stocks if it is profiting
// else u will not buy that stock as it is in loss
// 1 5 3  8 12
// 4+9
// 13

#include <iostream>

using namespace std;

int maxProfit(int price[],int n)
{
    int profit = 0;
    for(int i=0;i<n;i++)
    {
        if(price[i] < price[i+1])
        {
            profit += (price[i+1] - price[i]) ; 
        }
    }
    return profit;
}

int main()
{
    int arr[] = {1,5,3,8,12};
    int n=sizeof(arr)/sizeof(int);
    cout<<maxProfit(arr,n);

    // TC - O(n)
    // SC - O(1)

    return 0;
}
