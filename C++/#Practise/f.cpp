#include<bits/stdc++.h>

#define pb push_back
#define mod 1000000007

using namespace std;
 
vector <vector <long long>>vector_arr;

bool is_prime(long long n){
    if(n==1)
    return false;

    for(long long i=2;i*i<=n;i++){
        if(n%i==0)
            return false;
    }
    return true;
}


void insertion_sort_function(vector<vector<long long>>&final_vector, vector<long long>ind_array){
    long long n=final_vector.size();
    long long i,j,p=0;
    while(1)
    {
        p=0;
        for(i=0;i<n;i++){
            if(ind_array[i] >= final_vector[i].size())
                continue;
            p=1;
            for(j=ind_array[i]-1;j>=0;j--){
                if(final_vector[i][j] >= final_vector[i][j+1])
                    swap(final_vector[i][j],final_vector[i][j+1]);
            }
            ind_array[i]++;
        }
        if(p==0)
            break;
        vector<vector<long long>>vector_arr1(n,vector<long long>(n));
        for(i=0;i<n/2;i++){
            j=0;
           long long x=i,y=i;
           long long sz=final_vector[i].size();
           while(x < n-i){
               vector_arr1[x][y]=final_vector[i][j];
               x++,j++;
           }
           x=n-1-i,y=i+1;
           while(y < n-1-i){
            vector_arr1[x][y]=final_vector[i][j];
            y++,j++;
           }
        }
        if(n%2==1){
            vector_arr1[n/2][n/2]=final_vector[n/2][0];
        }
        i=(n+1)/2;
        while(i<n){
          j=0;
           long long x=i,y=i;
           long long sz=final_vector[i].size();
           while(x >= n-i-1){
               vector_arr1[x][y]=final_vector[i][j];
               x--,j++;
           }
           x=n-i-1,y=i-1;
           while(y > n-i-1){
            vector_arr1[x][y]=final_vector[i][j];
            y--,j++;
           }
           i++;
        }
        for(i=0;i<n;i++){
            for(j=0;j<n;j++)
                cout<<vector_arr1[i][j]<<" ";
        }
        cout<<endl;
    }
}

void merge_function()
{
    long long n=vector_arr.size(),i,j;
    vector<long long>ind_array(n/2,0);
    for(i=0;i<n/2;i++)
        ind_array[i]=vector_arr[i].size();
    while(1){
        long long p=0;
        for(i=0;i<n/2;i++){
            vector<long long>vector_arr1=vector_arr[i];
            for(j=0;j<vector_arr[n-1-i].size();j++)
                vector_arr1.pb(vector_arr[n-1-i][j]);

            if(ind_array[i] >= vector_arr1.size())
                continue;
            p=1;
            for(j=ind_array[i]-1;j>=0;j--){
                if(vector_arr1[j] >= vector_arr1[j+1])
                    swap(vector_arr1[j],vector_arr1[j+1]);
            }
            for(j=0;j<vector_arr[i].size();j++)
                vector_arr[i][j]=vector_arr1[j];
            for(long long k=0;k<vector_arr[n-1-i].size();k++)
                vector_arr[n-1-i][k]=vector_arr1[j++];
            ind_array[i]++;

        }
        if(p==0)
            break;

        vector<vector<long long>>vector_arr1(n,vector<long long>(n));
        for(i=0;i<n/2;i++){
            j=0;
           long long x=i,y=i;
           long long sz=vector_arr[i].size();
           while(x < n-i){
               vector_arr1[x][y]=vector_arr[i][j];
               x++,j++;
           }
           x=n-1-i,y=i+1;
           while(y < n-1-i){
            vector_arr1[x][y]=vector_arr[i][j];
            y++,j++;
           }
        }
        if(n%2==1){
            vector_arr1[n/2][n/2]=vector_arr[n/2][0];
        }
        i=(n+1)/2;
        while(i<n){
          j=0;
           long long x=i,y=i;
           long long sz=vector_arr[i].size();
           while(x >= n-i-1){
               vector_arr1[x][y]=vector_arr[i][j];
               x--,j++;
           }
           x=n-i-1,y=i-1;
           for(;y > n-i-1;y--,j++){
            vector_arr1[x][y]=vector_arr[i][j];
           }
           i++;
        }
        for(i=0;i<n;i++){
            for(j=0;j<n;j++)
                cout<<vector_arr1[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    long long test_cases;
    test_cases=1;
    long long n,m,i,j,k;

    while(test_cases--){
        cin>>n;
        vector<vector<long long>>final_vector(n,vector<long long>(n));
        k=n;
        vector<vector<long long>>v2;
        for(i=0;i<n;i++){
            for(j=0;j<n;j++)
                cin>>final_vector[i][j];
        }

        for(i=0;i<n/2;i++){
            vector<long long>vector_arr1;
            long long x=i,y=i;
            while(x < n-i){
                vector_arr1.pb(final_vector[x][y]);
                x++;
            }
            x=n-1-i,y=i+1;
            while(y < n-1-i){
                vector_arr1.pb(final_vector[x][y]);
                y++;
            }
            v2.pb(vector_arr1);
        }
        if(n%2==1){
            v2.pb({final_vector[n/2][n/2]});
        }
        for(i=(n+1)/2;i<n;i++){
            vector<long long>vector_arr1;
            long long x=i,y=i;
            while(x >= n-i-1){
               vector_arr1.pb(final_vector[x][y]);
               x--;
           }
           x=n-i-1,y=i-1;
           while(y > n-i-1){
            vector_arr1.pb(final_vector[x][y]);
            y--;
           }
            v2.pb(vector_arr1);
        }

        vector<long long>ind_array(n,1);
        vector_arr=v2;
        insertion_sort_function(v2,ind_array);
        vector_arr=v2;
        merge_function();
    }
    return 0;
}