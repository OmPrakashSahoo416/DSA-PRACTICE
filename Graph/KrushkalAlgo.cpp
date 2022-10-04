#include <bits/stdc++.h> 
using namespace std;
int findParent(int x, vector<int> &parent) {
    if(parent[x] == x){
        return x;
    }
    return parent[x] = findParent(parent[x], parent);
}
void unionn(int a, int b, vector<int> &rank, vector<int> &parent) {
    int x = findParent(a, parent);
    int y = findParent(b, parent);
    if(rank[x] == rank[y]) {
        parent[y] = x;
        rank[x]++;
    }else if(rank[x] < rank[y]) {
        parent[x] = y;
    }else{
        parent[y] = x;
    }
}
bool cmp(vector<int> &a, vector<int> &b){
    return a[2] < b[2];
}
int kruskalMST(int n, int m, vector<vector<int>> &graph) {
    vector<int>parent(n + 1);
    vector<int>rank(n + 1, 0);
    int ans = 0;
    for(int i = 1; i < n + 1; i++){
        parent[i] = i; 
    }
    sort(graph.begin(), graph.end(), cmp);
    for(auto it : graph) {
        int wt = it[2];
        int u = it[0];
        int v = it[1];
        if(findParent(u, parent) != findParent(v, parent)) {
            ans += wt;
            unionn(u, v, rank, parent);
        }
    }
    return ans;
}