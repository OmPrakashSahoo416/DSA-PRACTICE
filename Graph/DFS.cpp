class Solution {
  public:
  
    void dfs(int node, vector<int> &vis, vector<int> adj[], vector<int> &ans){
        ans.push_back(node);
        vis[node] = 1;
        for(auto it : adj[node]){
            if(vis[it] == 0){
                dfs(it, vis, adj, ans);
            }
        }
        return;
    }
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int>ans;
        vector<int>vis(V,0);
        for(int i = 0; i < V; i++){
            if(vis[i] != 1){
                dfs(i, vis, adj, ans);
            }
        }
        return ans;
    }
};