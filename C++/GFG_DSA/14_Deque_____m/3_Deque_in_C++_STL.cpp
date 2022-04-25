#include <iostream>
#include <cmath>
#include <bits/stdc++.h> 
#include <climits>
#include <deque>
using namespace std;


int main()
{
	deque<int> dq = {10, 20, 5, 30};

	auto it = dq.begin();

	it = dq.insert(it, 7);

	it = dq.insert(it, 2, 3);

	it = dq.erase(it + 1);

	cout << (*it) << endl;

	for(int i = 0; i < dq.size(); i++)
		cout<<dq[i]<<" ";

	it++;

	dq.insert(it, 20);

	dq.pop_front();
	dq.pop_back();

	cout<<dq.size()<<endl;
    cout<<endl;
	dq.push_front(5);
	dq.push_back(50);
    cout<<endl;

	for(auto x: dq)
		cout << x << " ";
    cout<<endl;

	cout << dq.front() << " " << dq.back();
    cout<<endl;

	return 0;
}