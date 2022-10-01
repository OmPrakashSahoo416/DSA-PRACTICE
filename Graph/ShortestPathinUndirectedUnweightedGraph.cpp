#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define pp pop_back
#define ll long long
#define all(x) (x).begin(), (x).end()
#define sz(x) (x).size()
#define mod 1e9 + 7

vector<int>shortestPath(int v, vector<pair<int, int>> &edges){
	vector<int>dis(v, INT_MAX);
	queue<int>q;
	q.push(0);
	dis[0] = 0;
	while(!q.empty()){
		int node = q.front();
		q.pop();
		for(int i = 0; i < sz(edges); i++){
			if(edges[i].first == node){
				if(dis[edges[i].second] == INT_MAX){
					q.push(edges[i].second);
				}
				dis[edges[i].second] = min(dis[edges[i].second], dis[node] + 1);

			}
		}
	}
	return dis;
}

void solution(){
	int n;
	cin>>n;
	vector<pair<int, int>>edges;
	int e;
	cin>>e;
	for(int i = 0; i < e; i++){
		int a, b;
		cin>>a>>b;
		edges.pb({a, b});
		edges.pb({b, a});
	}
	vector<int>ans = shortestPath(n, edges);
	for(int i = 0; i < ans.size(); i++){
		cout<<"Node 0 to "<<i<<" -- "<<ans[i]<<endl;
	}
	
}

int main(){
	// int t;
	// cin>>t;
	// while(t--){
		solution();
	// }
}