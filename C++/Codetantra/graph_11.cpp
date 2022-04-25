#include <bits/stdc++.h> 
using namespace std; 


int **graph;

vector<int> djikstra(vector<int> &dist,int src,int V) 
{ 
	dist[src]=0;
	vector<bool> fin(V,false);

	for (int count = 0; count < V-1 ; count++) 
	{ 
		int u = -1; 

		for(int i=0;i<V;i++)
		    if(!fin[i]&&(u==-1||dist[i]<dist[u]))
		        u=i;
		fin[u] = true; 
		
		for (int v = 0; v < V; v++) 

			if (graph[u][v]!=0 && fin[v] == false) 
				dist[v] = min(dist[v],dist[u]+graph[u][v]); 
	} 
    return dist;
} 

int main() 
{ 

	
    string s = "0 8 9 8 0 7 9 7 100000";
	int start = 1;
	int end = 3;

    // string s = "0 6 0 1 0 6 0 5 0 2 0 5 0 0 5 1 0 0 0 1 0 2 5 1 0";
	// int start = 3;
	// int end = 1;



    vector <string> v_array;
	int counter = 0;
	int k;
	int n = 0;
    for(k=0;k<s.length();k++)
    {
        if(s[k]==' ')
        {
            v_array.push_back(s.substr(counter,k-counter));
            counter = k+1;
			n++;
        }
    }
    v_array.push_back(s.substr(counter,k-counter));
	n++;

	// int n = s.length()/2+1;
	// cout<<no;
    counter = 0;
    int r = sqrt(n);
    int c = sqrt(n);

    graph = new int*[r];
    for(int i=0;i<r;i++)
    {
        graph[i] = new int[c];    
		for(int j=0;j<c;j++);
	}

    for(int i=0;i<r;i++)
    {
		for(int j=0;j<c;j++)
		{
			graph[i][j] = stoi(v_array[counter++]);
		}
	}
 

	int V = r;
	vector<int> dist(V,INT_MAX);
    djikstra(dist,start-1,V);
    cout<<dist[end-1];



	return 0; 
} 
