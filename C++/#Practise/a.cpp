#include <bits/stdc++.h>
#include <string>
using namespace std;

void permute(string s , string answer)
{
	if(s.length() == 0)
	{
		cout<<answer<<endl;
		return;
	}
	for(int i=0 ; i<s.length() ; i++)
	{
		char ch = s[i];
		string left_substr = s.substr(0,i);
		string right_substr = s.substr(i+1);
		string rest = left_substr + right_substr;
		permute(rest , answer+ch);
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
	permute(s , answer);
	return 0;
}
