#include <bits/stdc++.h>

using namespace std;

int main()
{
    string start = "12,13";
    string end = "100,13";

   vector<string> result_1;
   stringstream s_stream_1(start); //create string stream from the string
   while(s_stream_1.good()) 
   {
      string substr;
      getline(s_stream_1, substr, ','); //get first string delimited by comma
      result_1.push_back(substr);
   }

    int start_r = stoi(result_1[0]);
    int start_c = stoi(result_1[1]);

    cout<<start_r<<" "<<start_c;

   vector<string> result_2;
   stringstream s_stream_2(end); //create string stream from the string
   while(s_stream_2.good()) 
   {
      string substr;
      getline(s_stream_2, substr, ','); //get first string delimited by comma
      result_2.push_back(substr);
   }

    int end_r = stoi(result_2[0]);
    int end_c = stoi(result_2[1]);

    cout<<endl<<end_r*20<<" "<<end_c;

    return 0;
}