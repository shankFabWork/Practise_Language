#include <iostream>
#include <vector>

using namespace std;

int main()
{
    size_t t;
    cin>>t;
    while(t--)
    {
        long long int n,d;
        cin>>n>>d;
        vector <int> arr;
        int i = 0;
        int r = 0,nr = 0;
        for(int k=0;k<n;k++)
        {
            int val;
            cin>>val;
            arr.push_back(val);
            if(val >= 80 && val <= 9)
            {
                r++;
            }
        }
        nr = n - r;
        while(r > 0)
        {
            r = r - d;
            i++;
        }
        while(nr > 0)
        {
            nr = nr - d;
            i++;
        }
        cout<<i<<endl;
    }

    return 0;
}