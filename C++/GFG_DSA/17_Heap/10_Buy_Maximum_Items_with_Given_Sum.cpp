    #include <iostream>
    #include <algorithm>
    #include <queue>

    using namespace std;


    // Problem Statement
    // the problem of buying the maximum items with a given sum.
    // repetations are not allowed

    // I/P->
    // 1 12 5 111 200 ->items
    // sum=10

    // O/P->
    // 2
    //need to find maximum items
    // 1 5


    // I/P->
    // 20 10 5 30 100
    // sum=35

    // O/P->
    // 3
    // 20 10 5
    // 30 5 will give u 2

    void maximum_items_with_a_given_sum_one(int arr[],int n,int sum)
    {
        sort(arr,arr+n);
        int res=0;
        for(int i=0;i<n;i++)
        {
            if(sum >= arr[i])
            {
                sum =sum - arr[i];
                res = res + 1;
            }
        }
        cout<<(res)<<endl;
    }

    void maximum_items_with_a_given_sum_two(int arr[],int n,int sum)
    {
        priority_queue <int,vector<int>,greater<int>> pq;
        int res=0;
        for(int i=0;i<n;i++)
        {
            pq.push(arr[i]);
        }
        while(pq.empty() == false)
        {
            sum=sum-pq.top();
            res = res + 1;
            pq.pop();
            if(sum <= 0)
            {
                break;
            }
        }
        cout<<(res);
    }

    int main()
    {
        // int arr[]={1,12,5,111,200};
        // int sum=10;
        //answer -> 2

        int arr[]={20,10,5,30,100};
        int sum=35;
        //answer -> 3

        int n=sizeof(arr)/sizeof(int);

        maximum_items_with_a_given_sum_one(arr,n,sum);
        //Time Complexity -> O(n.log(n) )
        //Space Complexity -> O(1)

        // maximum_items_with_a_given_sum_two(arr,n,sum);
        //Time Complexity -> O(n) + O(res + log(n) )
        //Space Complexity -> O(n)

        return 0;
    }


