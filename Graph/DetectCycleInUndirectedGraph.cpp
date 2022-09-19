#include<bits/stdc++.h>
bool hasCycle(int node, vector<int> &vis, vector<vector<int>>& edges){
    queue<pair<int,int>>q;
    q.push({node, -1});
    vis[node] = 1;
    while(!q.empty()){
        int par = q.front().second;
        int nde = q.front().first;
        q.pop();
        for(auto i : edges){
            if(i[0] == nde){
                if(vis[i[1]] == 0){
                    vis[i[1]] = 1;
                    q.push({i[1], nde});
                }else{
                    if(i[1] != par && par != -1){
                        return true;
                    }
                }
            }
            if(i[1] == nde){
                if(vis[i[0]] == 0){
                    vis[i[0]] = 1;
                    q.push({i[0], nde});
                }else{
                    if(i[0] != par && par != -1){
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    vector<int>vis(n + 1, 0);
    for(int i = 1; i < n + 1; i++){
        if(vis[i] == 0){
            if(hasCycle(i, vis, edges)){
                return "Yes";
            }
        }
    }
    return "No";
}
