#include<bits/stdc++.h>
using namespace std;
bool checkforcycle(int node, int prev, vector<int>&vis,vector<int>adj[]){

	vis[node]=1;

	for(auto it:adj[node]){
		if(!vis[it])
			if(checkforcycle(it,node,vis,adj))
				return true;
		else if(it!=prev)
			return true;
	}

	return false;
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
	for(int i=1;i<=v;i++){
     cout<<i<<":";
     for(auto it:adj[i])
         cout<<it<<" ";
     cout<<endl;
    }
	vector<int>storedfs;
	vector<int>vis(v+1,0);

	bool ans=0;
	for(int i=1;i<=v;i++){
		if(!vis[i])
			ans=checkforcycle(i,-1,vis,adj);
	}

	if(ans)
		cout<<"Cycle Exists\n";
	else
		cout<<"Cycle doesnt exist\n";
}
