#include<bits/stdc++.h>

bool hasCycle(int node, vector<int> &vis, vector<int> &dfsvis, vector<pair<int, int>> &edges){
    vis[node] = 1;
    dfsvis[node] = 1;
    for(auto it : edges){
        if(it.first == node){
            if(vis[it.second] == 0){
                if(hasCycle(it.second, vis, dfsvis, edges))return true;
            }else{
                if(dfsvis[it.second] == 1){
                    return true;
                }
            }
        }
    }
    dfsvis[node] = 0;
    return false;
}

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
    vector<int> vis(n + 1, 0);
    vector<int> dfsvis(n + 1, 0);
    for(int i = 1; i <= n ; i++){
        if(vis[i] == 0){
            if(hasCycle(i, vis, dfsvis, edges)){
                return 1;
            }
        }
    }    
    return 0;
}