#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define pp pop_back
#define ll long long
#define all(x) (x).begin(), (x).end()
#define sz(x) (x).size()
#define mod 1e9 + 7

void findTopoSort(int n, stack<int> &ans, vector<pair<int, int>> adj[], vector<int> &vis) {
	vis[n] = 1;
	for(int i = 0; i < adj[n].size(); i++) {
		if(vis[adj[n][i].first] == 0){
			findTopoSort(adj[n][i].first, ans, adj, vis);
		}
	}
	ans.push(n);
}

vector<int> shortestPath(int n, vector<pair<int, int>> adj[]){
	stack<int>st;
	vector<int>vis(n, 0);
	vector<int> dis(n, INT_MAX);
	for(int i = 0; i < n; i++){
		if(vis[i] == 0){
			findTopoSort(i, st, adj, vis);
		}
	}
	dis[0] = 0;
	while(!st.empty()){
		int node = st.top();
		// cout<<node<<endl;
		st.pop();
		if(dis[node] != INT_MAX){
			for(int i = 0; i < adj[node].size(); i++){
				dis[adj[node][i].first] = min(dis[adj[node][i].first], dis[node] + adj[node][i].second);
			}
		}
	}
	return dis;
}


void solution(){
	// Considering source as node 0.
	int n;
	cin>>n;
	int e;
	cin>>e;
	vector<pair<int, int>>adj[n];
	for(int i = 0; i < e; i++){
		int u, v, wt;
		cin>>u>>v>>wt;
		adj[u].pb({v, wt});
	}
	vector<int> ans = shortestPath(n, adj);
	for(int i =  0; i < sz(ans); i++){
		cout<<"Node 0 to Node "<<i<<" -- "<<ans[i]<<endl;
	}
}

int main(){
	// int t;
	// cin>>t;
	// while(t--){
		solution();
	// }
}