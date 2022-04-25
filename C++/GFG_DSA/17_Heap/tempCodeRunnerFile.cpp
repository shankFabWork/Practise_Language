
    int arr[] = { -10, -50, 20, 17, 80 }; 
    int x = 20, k = 2; 

    int n=sizeof(arr)/sizeof(int);

    // K_Closest_Elements_one(arr,n,x,k);
    //Time Complexity -> O(n.k)
    //Space Complexity -> O(n)
    // visited array space

    K_Closest_Elements_two(arr,n,x,k);