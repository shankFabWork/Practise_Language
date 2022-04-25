#include <iostream>
#include <deque>

using namespace std;

int main()
{
    int petrol[] = {50,10,60,100};
    int dist[] = {30,20,100,10};
    int n = sizeof(dist)/sizeof(dist[0]);

    int prev_pet = 0;
    deque <int> dq;
    int curr = 0;
    for(int i=0;i<n;i++)
    {
        curr += petrol[i] - dist[i];
        if(curr < 0)
        {
            start = i+1;
            prev_pet = curr ;
            curr = 0;
        }
    }

}