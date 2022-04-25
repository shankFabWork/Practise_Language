#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector <int> nums = {3,6,2,5,1,6};
    int n = nums.size();
    bool bool_arr[n+1];
    for(int i=0;i<=n;i++)
    {
        bool_arr[i] = 0;
    }
    for(int i=0;i<n;i++)
    {
        if(bool_arr[nums[i]] == 0)
        {
            bool_arr[nums[i]] = 1;
        }
        else if(bool_arr[nums[i]] == 1)
        {
            cout<<nums[i];
            break;
        }
    }
}