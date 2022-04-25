// Rules
// 1) One Unit By Every Job
// 2) Only one job can  
//    be assigned at a time
// 3) Time starts with 0

// I/P
// deadline:  4  1   1  1
// profit  : 70  80 30  100
// O/P
// 170

// I/P
// deadline:  2  2   2  3
// profit  : 50  60 20  30
// O/P
// 140

// I/P
// deadline:  2   1  2  1  3
// profit  : 100 50 10 20 30
// O/P
// 180

#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

class JSP
{
    public:
    char id;
    int deadline;
    int profit;
};

bool myComp(JSP p1,JSP p2)
{
    return p1.profit > p2.profit;
}

void Job_Sequencing_Problem(JSP arr[],int n)
{
    sort(arr,arr+n,myComp);

    bool slot[n];
    for(int i=0;i<n;i++)
    {
        slot[i] = false;
    }

    int result[n];
    for(int i=0;i<n;i++)
    {
        // if by mistake deadline 
        // is more than n
        /// i.e. 6 or 7 or so on in this case
        for(int j = min(n,arr[i].deadline)-1;j>=0;j--)
        {
            if(slot[j] == false)
            {
                result[j] = i;
                slot[j] = true;
                break;
            }
        }
    }

    for(int i=0;i<n;i++)
    {
        if(slot[i] == true)
        {
            cout<<arr[result[i]].id<<" ";
            cout<<arr[result[i]].deadline<<" ";
            cout<<arr[result[i]].profit;
            cout<<endl;
        }
    }
}

int main()
{
    JSP arr[] =
    { 
        {'a', 2, 100}, 
        {'b', 1, 19}, 
        {'c', 2, 27},
        {'d', 1, 25}, 
        {'e', 3, 15}
    };
    int n = sizeof(arr)/sizeof(arr[0]);
    Job_Sequencing_Problem(arr,n);
    // Time Complexity -> O(N^2)
    // Space Complexity -> O(n)
    // 0 to 4 
    // 0 1 2
    // t t t 
    // 1 0 4
    
    // 0 
    // 1
    // 2

    return 0;
}