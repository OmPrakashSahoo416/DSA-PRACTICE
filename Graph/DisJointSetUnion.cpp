#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define pp pop_back
#define ll long long
#define all(x) (x).begin(), (x).end()
#define sz(x) (x).size()
#define mod 1e9 + 7

int Parent[10005];
int rank[10005];

void make(){
	for(int i = 0 ; i < n; i++){
		Parent[i] = i;
		rank[i] = 0;
	}
}

void union(int u, int v){
	u = findParent(u);
	v = findParent(v);
	if(rank(u) > rank(v)) {
		Parent[v] = findParent(u);
	}else if(rank(u) < rank(v)){
		Parent[u] = findParent(v);
	}else{
		Parent[v] = findParent(u);
		rank[u]++;
	}
}

int findParent(int node){
	if(Parent[node] == node)return node;

	return Parent[node] = findParent(Parent[node]);
}

void solution(){
	
}

int main(){
	int t;
	cin>>t;
	while(t--){
		solution();
	}
}