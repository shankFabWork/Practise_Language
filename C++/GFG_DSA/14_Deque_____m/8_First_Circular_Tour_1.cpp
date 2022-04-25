#include <iostream>

using namespace std;

// int petrol[] = {4,8,7,4};
// int dist[] = {6,5,3,5};

// int petrol[] = {4,8};
// int dist[] = {5,6};

// int petrol[] = {8,9,4};
// int dist[] = {5,10,12};

int main()
{
    // int petrol[] = {4,8,7,4};
    // int dist[] = {6,5,3,5};

    int petrol[] = {8,9,4};
    int dist[] = {5,10,12};
    int counter = 0;
    int n = sizeof(dist)/sizeof(dist[0]);
    for(int start = 0;start < n;start++)
    {
        int done = 0;
        int curr_petrol = 0;
        int i = start;
        for(int end = start;end < n;end = (end+1)%n)
        {
            curr_petrol = petrol[end] - dist[end];
            if(curr_petrol < 0)
            {
                break;
            }
            if(start == end)
            {
                done = 1;
            }
        }
        if(done == 1)
        {
            cout<<start+1<<" ";
            counter++;
        }
    }
    if(counter == 0)
    {
        cout<<-1;
    }

}