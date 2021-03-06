#include<bits/stdc++.h>
using namespace std;
const int S=1e3+10;
vector<int> g[S];
bool visit[S];
void DFS(int src)
{
	cout<<src<<" ";
	visit[src]=true;
	for(auto nbr:g[src])
	{
		if(visit[nbr])
		continue;
		DFS(nbr);
	}
}
void BFS(int src)
{
	queue<int> r;
	r.push(src);
	visit[src]=true;
	while(!r.empty())
	{
		int cur_src=r.front();
		r.pop();
		cout<<cur_src<<" ";
		for(auto child:g[cur_src]){
			if(!visit[child]){
				r.push(child);
				visit[child]=true;
			}
		}
	}
}
int main()
{
	int a,b;
	cout<<"Enter number of vertices and edges\n";
	cin>>a>>b;
	for(int i=0;i<b;i++)
	{
	  int v1,v2;
	  cout<<"Enter edge\n";
	  cin>>v1>>v2;
	  g[v1].push_back(v2);
	  g[v2].push_back(v1);
	}
	BFS(1);
	cout<<endl;
	DFS(1);
}
