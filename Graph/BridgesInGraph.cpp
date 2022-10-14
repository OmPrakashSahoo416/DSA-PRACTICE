#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define pp pop_back
#define ll long long
#define all(x) (x).begin(), (x).end()
#define sz(x) (x).size()
#define mod 1e9 + 7

void dfs(int v, int par, vector<int> adj[], vector<int> &low,
	vector<int> &tin, vector<int> &vis, int count) {

	vis[v] = 1;
	tin[v] = low[v] = count++;
	for(auto it : adj[v]) {
		if(it == par)continue;
		if(vis[it] == 0){
			dfs(it, v, adj, low, tin, vis, count);
			low[v] = min(low[it], low[v]);
			if(low[it] > tin[v]) {
				cout<<v<<" : "<<it<<endl;
			}
		}else{
			low[v] = min(low[v], tin[it]);
		}
	}

}

void solution(){
	int v, e;
	cin >> v >> e;
	vector<int>adj[v + 1];
	for(int i = 0; i < v; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	vector<int>tin(v + 1, -1);
	vector<int>low(v + 1, -1);
	vector<int>vis(v + 1, 0);
	for(int i = 1; i <= v; i++){
		if(vis[i] == 0){
			dfs(i, -1, adj, low, tin, vis, 0);
		}
	}
}

int main(){
	int t;
	cin>>t;
	while(t--){
		solution();
	}
}