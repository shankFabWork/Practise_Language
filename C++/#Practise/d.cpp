#include <bits/stdc++.h>

using namespace std;

bool string_checker(string txt,int k)
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
    cout<<endl;
    for(int data:c_arr)
    {
        if(data > 2)
        {
            return false;
        }
    }
    cout<<endl;
    for(int data:m_arr)
    {
        if(data > k)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int c,m,k;
    cin>>c>>m>>k;
    string str="";
    while(c != 0 && m != 0)
    {
        if(c == 0)
        {
            continue;
        }
        else if(c > 2)
        {
            c = c-1;
            str += "C";
        }
        else if(c > 2)
        {
            c = c-2;
            str += "CC";
        }
        else if(c == 1)
        {
            c = c-1;
            str += "C";
        }
        if(m == 0)
        {
            continue;
        }
        else if(m >= k)
        {
            m = m-k;
            for(int i=0;i<k;i++)
            {
                str += 'M';
            }
        }
        else if(m < k)
        {
            m = m-m;
            for(int i=0;i<m;i++)
            {
                str += 'M';
            }
        }
    }
    for(int i=0;i<c;i++)
    {
        str += 'C';
    }
    cout<<str;
}