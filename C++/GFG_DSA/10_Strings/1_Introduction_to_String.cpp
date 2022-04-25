// String ::
// Sequence of character
// small set
// contiguous integer value for 'a' to 'z'
// ans 'A' to 'Z' in both ascii 
// and utf-8 (unicode standard format)

// C/C++
// char :  ASCII , 8-bit

#include <iostream>
#include <string>

using namespace std;

const int CHAR = 256;

// strig sort 
// string frequency
void sort_string(string str)
{
    int count[CHAR] = {0};

	for(int i=0;i<str.length();i++)
	{
		count[str[i]]++;
	}
	for(int i=0;i<CHAR;i++)
	{
		if(count[i] != 0)
		{
			for(int j=0;j<count[i];j++)
			{
				cout<<(char)i<<" ";
			}
		}
	}
}

void string_frequency(string str)
{
    int count[26] = {0};

    for(int i=0;i<str.length();i++)
    {
        count[str[i]-'a']++;
    }

    for(int i=0;i<26;i++)
    {
        if(count[i] > 0)
        {
            // typecasting
            cout<<(char)(i+'a')<<" "<<count[i]<<endl;
        }
    }
}

int main()
{
    string str = "geeksforgeeks";


    // string str="shankFab";

    string_frequency(str);
    // Time Complexity -> O(n+m)
    // 'm' is number of alphabet in english
    // Space Complexity -> O(CHAR)

    sort_string(str);
    // Time Complexity -> O(CHAR*m)
    // 'm' is number of repeated elements
    // Space Complexity -> O(CHAR)

    return 0;
}