class Solution {
public:
    vector<pair<int, int>>v = {
        {1, 0}, {-1, 0},
        {0, 1}, {0, -1}
    };
    
    bool isValid(int i, int j, vector<vector<char>> &grid){
        return i >= 0 && j >= 0 && i < grid.size() && j < grid[0].size() && grid[i][j] == '1';
    }
    
    void dfs(int i, int j, vector<vector<char>> &grid, vector<vector<int>> &vis){
        if(vis[i][j] == 1)return;
        vis[i][j] = 1;
        
        for(int ii = 0; ii < v.size(); ii++){
            if(isValid(i + v[ii].first, j + v[ii].second, grid)){
                dfs(i + v[ii].first, j + v[ii].second, grid, vis);
            }
        }
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        vector<int>vt(grid[0].size(), 0);
        vector<vector<int>>visited(grid.size(), vt);
        int ans = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == '1'){
                    if(visited[i][j] == 0){
                        ans++;
                        dfs(i, j, grid, visited);
                    }
                }
            }
        } 
        return ans;
    }
};