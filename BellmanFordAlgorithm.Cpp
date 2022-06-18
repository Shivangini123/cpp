#include<bits/stdc++.h>
using namespace std;
struct node {
    int s;
    int t;
    int vt; 
    node(int first, int second, int weight) {
        s = first;
        t = second;
        vt = weight;
    }
};

int main(){
    int A=6,b=7;
    vector<node> edges; 
	edges.push_back(node(0,1,5));
	edges.push_back(node(1,2,-2));
	edges.push_back(node(1,5,-3));
	edges.push_back(node(2,4,3));
	edges.push_back(node(3,2,6));
	edges.push_back(node(3,4,-2));
	edges.push_back(node(5,3,1));
    int src=0;
    int inf = 10000000; 
    vector<int> dist(A, inf); 
    dist[src] = 0; 
    for(int i = 1;i<=A-1;i++) {
        for(auto it: edges) {
            if(dist[it.s] + it.vt < dist[it.t]) {
                dist[it.t] = dist[it.s] + it.vt; 
            }
        }
    }

    int fl = 0; 
    for(auto it: edges) {
        if(dist[it.s] + it.vt < dist[it.t]) {
            cout << -1; 
            fl = 1; 
            break; 
        }
    }
    
    if(!fl) {
    	cout<<"Vertex \t Distace from Source"<<endl;
        for(int i = 0;i<A;i++) {
        	cout<<i<<" \t\t"<<dist[i]<<endl;
        }
    }
    return 0;
}
