#include<bits/stdc++.h>
using namespace std;
void dfs(int node, vector<int>&vis, vector<int>adj[],vector<int>&storedfs){
	storedfs.push_back(node);
	vis[node]=1;

	for(auto it:adj[node]){
		if(!vis[it])
			dfs(it,vis,adj,storedfs);
	}
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE
	int v,e;
	cin>>v>>e;
	//creating adjacency list
	vector<int>adj[v+1];
	for(int i=0;i<e;i++){
		int v1,v2;
		cin>>v1>>v2;

		adj[v1].push_back(v2);
		adj[v2].push_back(v1);
	}
	for(int i=0;i<=v;i++){
     cout<<i<<":";
     for(auto it:adj[i])
         cout<<it<<" ";
     cout<<endl;cout<<endl;
    }
	vector<int>storedfs;
	vector<int>vis(v+1,0);

	for(int i=1;i<=v;i++){
		if(!vis[i])
			dfs(i,vis,adj,storedfs);
	}

	for(int i=0;i<v;i++){
		cout<<storedfs[i]<<" ";
	}
}
