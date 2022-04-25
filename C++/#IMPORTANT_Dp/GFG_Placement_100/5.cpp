// Coin Change
// Count Combination

#include <iostream>

using namespace std;

int getCoin(int coin[],int n,int sum)
{
    if(n == 0)
    {
        return 0;
    }
    if(sum == 0)
    {
        return 1;
    }
    int res = getCoin(coin,n-1,sum);
    if(coin[n-1] <= sum)
    {
        res = res + getCoin(coin,n,sum-coin[n-1]);
    }
    return res;
}

int main()
{
    int coin[] = {2,5,3,6};
    int n = sizeof(coin)/sizeof(coin[0]);
    int sum = 10;

    cout<<getCoin(coin,n,sum);

}