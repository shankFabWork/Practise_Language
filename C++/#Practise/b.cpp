#include <bits/stdc++.h>

using namespace std;

bool str_checker(string txt,int k)
{
    int counter = 1;
    vector <int> c_arr;
    vector <int> m_arr;
    for(int i=0;i<txt.length()-1;i++)
    {
        if(txt[i] == txt[i+1])
        {
            counter++;
        }
        else
        {
            if(txt[i] == 'C')
            {
                c_arr.push_back(counter);
            }
            else
            {
                m_arr.push_back(counter);
            }
            counter = 1;
        }
    }
    if(txt[txt.length()-1] == 'C')
    {
        c_arr.push_back(counter);
    }
    else
    {
        m_arr.push_back(counter);
    }
    for(int data:c_arr)
    {
        if(data > 2)
        {
            return false;
        }
    }
    for(int data:m_arr)
    {
        if(data > k)
        {
            return false;
        }
    }
    return true;
}

int g_counter = 0;
void permute(string s , string answer,int k)
{
	if(s.length() == 0)
	{
        bool ans = str_checker(answer,k);
        // cout<<answer<<" "<<ans<<endl;
        if(ans)
        {
            g_counter++;
        }
		return;
	}
	for(int i=0 ; i<s.length() ; i++)
	{
		char ch = s[i];
		string left_substr = s.substr(0,i);
		string right_substr = s.substr(i+1);
		string rest = left_substr + right_substr;
		permute(rest , answer+ch,k);
	}
}

int main()
{
    int c,m,k;
	cin>>c>>m>>k;
	string s;
	for(int i=0;i<c;i++)
	{
		s += 'C';
	}
	for(int i=0;i<m;i++)
	{
		s += 'M';
	}
	string answer="";
	// permute(s , answer,k);
    // cout<<g_counter;
    // cout<<CCMCCMCC;
    cout<<str_checker("CCCMMCCC",2);
}