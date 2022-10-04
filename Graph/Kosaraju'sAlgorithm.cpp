#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define pp pop_back
#define ll long long
#define all(x) (x).begin(), (x).end()
#define sz(x) (x).size()
#define mod 1e9 + 7

void dfs(int node, stack<int> &ans, vector<int> &vis, vector<pair<int, int>> &graph) {
	vis[node] = 1;
	for(auto it : graph) {
		if(it.first == node) {
			if(vis[it.second] == 0){
				dfs(it.second, ans, vis, graph);
			}
		}
	}
	ans.push(node);
}

void ddfs(int node, vector<int> &vis, vector<int> &a, vector<pair<int, int>> &graph) {
	vis[node] = 1;
	a.pb(node);
	for(auto it : graph) {
		if(it.first == node) {
			if(vis[it.second] == 0){
				ddfs(it.second, vis, a, graph);
			}
		}
	}
}

vector<vector<int>> Kosaraju_Algo(int v, vector<pair<int, int>> &graph) {
	vector<vector<int>> ans;
	vector<pair<int, int>>transpose(graph.size());

	// 1. Finding transpose...
	for(int i = 0; i < graph.size(); i++) {
		transpose[i] = {graph[i].second, graph[i].first};
	}

	// 2. Finding Topo Sort...
	vector<int>vis(v, 0);
	stack<int>st;
	for(int i = 0; i < v; i++){
		if(vis[i] == 0){
			dfs(i, st, vis, graph);
		}
	}

	// 3. Finding SCC... 
	for(int i = 0; i < vis.size(); i++) {
		vis[i] = 0;
	}

	while(!st.empty()) {
		int node = st.top();
		st.pop();
		if(vis[node] == 1)continue;
		vector<int>a;
		ddfs(node, vis, a, transpose);
		ans.pb(a);
	}
	return ans;
}

void solution(){
	int v, e;
	cin>>v>>e;
	vector<pair<int, int>>graph(e);
	for(int i = 0; i < e; i++) {
		int x, y;
		cin>>x>>y;
		pair<int, int>p = {x, y};
		graph[i] = p;
	}
	vector<vector<int>>ans = Kosaraju_Algo(v, graph);
	for(int i = 0; i < ans.size(); i++) {
		for(int j = 0; j < ans[i].size(); j++) {
			cout<<ans[i][j]<<"->";
		}
		cout<<endl;
	}
}

int main(){
	int t;
	cin>>t;
	while(t--){
		solution();
	}
}