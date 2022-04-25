// Given a string , print all those permutations
// which do not contain "AB" as a substring

// I/P : str = "ABC"
// O/P : ACB , BAC , BCA , CBA

#include <iostream>
#include <algorithm>

using namespace std;

void swap(char *a,char *b)
{
    char c;
    c = *a;
    *a = *b;
    *b = c;
}

void permute(string str,int l,int r)
{
    if(l == r)
    {
        if(str.find("AB") == string::npos)
        {
            cout<<str<<endl;
        }
    }
    else
    {
        for(int i=l;i<=r;i++)
        {
            swap(str[i],str[l]);
            permute(str,l+1,r);
            swap(str[i],str[l]);
        }           
    }
}

// l!=0     , l-1 , i 
// r==(l+1) , i   , l
bool isSafe(string str,int l, int i, int r){
    if(l!=0 && str[l-1]=='A' && str[i]=='B')
        return false;
    if(r==(l+1) && str[i]=='A' && str[l]=='B')
        return false;
    return true;
}

void efficient_permute(string str,int l,int r)
{
    if(l == r)
    {
        cout<<str<<endl;
    }
    else
    {
        for(int i=l;i<=r;i++)
        {
            // if we will remove is Safe function
            // we will get all permutations
            if(isSafe(str,l,i,r))
            {
                swap(str[i],str[l]);
                efficient_permute(str,l+1,r);
                swap(str[i],str[l]);
            }
        }           
    }
}

int main()
{
    string str = "ABC";
    // permute(str,0,str.length()-1);
    // Time Complexity -> O(N*N!)
    cout<<endl;
    efficient_permute(str,0,str.length()-1);
    // Time Complexity -> O(N*N!)
    // in this solution we
    // cut down recursive calls 
    // but suppose we write 
    // "bcd" then we will run (n*n!)
    return 0;
}