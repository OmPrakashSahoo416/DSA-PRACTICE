#include <bits/stdc++.h> 
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    vector<int> ans(v);
    queue<int>q;
    vector<int>indeg(v, 0);
    for(auto i : edges){
        indeg[i[1]]++;
    }
    for(int i = 0; i < v; i++){
        if(indeg[i] == 0){
            q.push(i);
        }
    }
    int ind = 0;
    while(!q.empty()){
        if(ind == v)return ans;
        int x = q.front();
        q.pop();
        ans[ind++] = x;
        for(int i = 0; i < edges.size(); i++){
            if(edges[i][0] == x){
                indeg[edges[i][1]]--;
                if(indeg[edges[i][1]] == 0){
                    q.push(edges[i][1]);
                }
            }
        }
    }
    return ans;   
}