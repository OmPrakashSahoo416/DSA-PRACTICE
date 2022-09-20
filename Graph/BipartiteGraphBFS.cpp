class Solution {
public:
    
    bool checkBipartite(int node, vector<int> &color, vector<vector<int>> &graph){
        queue<int>q;
        q.push(node);
        color[node] = 0;
        while(!q.empty()){
            int x = q.front();
            q.pop();
            int col = color[x];
            for(auto i : graph[x]){
                if(color[i] == -1){
                    if(col == 0){
                        color[i] = 1;
                    }else{
                        color[i] = 0;
                    }
                    q.push(i);
                }else{
                    if(color[i] == col)return false;
                }
            }
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>color(n, -1);
        for(int i = 0; i < n; i++){
            if(color[i] == -1){
                if(checkBipartite(i, color, graph) == false){
                    return false;
                }
            }
        }
        return true;
    }
};