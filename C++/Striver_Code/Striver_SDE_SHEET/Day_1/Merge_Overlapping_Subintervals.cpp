#include <bits/stdc++.h>

using namespace std;

int main()
{

    vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};
    sort(intervals.begin(),intervals.end());
    vector <int> temp_interval = intervals[0];
    vector<vector<int>> merge_interval;

    int start = 1;
    for(auto it:intervals)
    {
        if(it[0] <= temp_interval[1])
        {
            temp_interval[1] = max(temp_interval[1],it[1]);
        }
        else
        {
            merge_interval.push_back(temp_interval);
            temp_interval = it;
        }
    }
    merge_interval.push_back(temp_interval);
    for(auto it:merge_interval)
    {
        cout<<it[0]<<" "<<it[1]<<endl;
    }
    return 0;
}