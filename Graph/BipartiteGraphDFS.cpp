
    bool checkBipartite(int node, vector<int> &color, vector<vector<int>> &edges){

        for(auto i : edges[node]){
            if(color[i] == -1){
                if(color[node] == 1){
                    color[i] = 0;
                }else{
                    color[i] = 1;
                }
                if(!checkBipartite(i, color, edges))return false;
            }else{
                if(color[i] == color[node])return false;
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