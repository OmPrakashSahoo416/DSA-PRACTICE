#include <bits/stdc++.h> 

void bfs(int node, vector<int> &ans, vector<pair<int, int>> &edges, vector<int> &vis){
    queue<int>q;
    q.push(node);
    vis[node] = 1;
    while(!q.empty()){
        int nd = q.front();
        ans.push_back(nd);
        q.pop();
        for(auto it : edges){
            if(it.first == nd){
                if(vis[it.second] == 0){
                    vis[it.second] = 1;
                    q.push(it.second);
                }
            }
        }
    }
}

vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    vector<int>ans;
    vector<int>vis(vertex, 0);
    sort(edges.begin(), edges.end());
    for(int i = 0; i < vertex; i++){
        if(vis[i] == 0){
            bfs(i, ans, edges, vis);
        }
    }
    return ans;
}