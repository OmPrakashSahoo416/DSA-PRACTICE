#include<bits/stdc++.h>
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
    vector<int>ans;
    queue<int>q;
    vector<int>indeg(n + 1, 0);
    for(int i = 0; i < edges.size(); i++){
        indeg[edges[i].second]++;
    }
    for(int i = 1; i < indeg.size(); i++){
        if(indeg[i] == 0){
            q.push(i);
        }
    }
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        ans.push_back(node);
        for(int i = 0; i < edges.size(); i++){
            if(edges[i].first == node){
                indeg[edges[i].second]--;
                if(indeg[edges[i].second] == 0){
                    q.push(edges[i].second);
                }
            }
        }
    }
    if(ans.size() == n)return 0;
    return 1;
}