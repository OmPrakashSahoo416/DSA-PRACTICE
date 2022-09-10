vector<pair<int,int>>moves = {
        {-1, 0}, {1, 0},
        {0, -1}, {0, 1}
    };
    bool isValid(int x, int y, vector<vector<int>>&grid){
        int n = grid.size();
        int m = grid[0].size();
        if(x < n && y < m && x >= 0 && y >= 0){
            return true;
        }
        return false;
    }
    
    int bfs(vector<vector<int>> &grid, map<pair<int,int>, int> &level){
        queue<pair<int,int>>q;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 2){
                    q.push({i, j});
                    level[{i, j}] = 0;
                }
            }
        }
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            for(int k = 0; k < moves.size(); k++){
                int x1 = moves[k].first + x;
                int y1 = moves[k].second + y;
                if(isValid(x1, y1, grid)){
                    if(grid[x1][y1] == 1){
                        q.push({x1, y1});
                        grid[x1][y1] = 2;
                        level[{x1, y1}] = 1 + level[{x, y}];
                    }
                }
            }
            q.pop();
        }
        int ans = 0;
        for(auto it : level){
            ans = max(ans, it.second);
        }
        return ans;
    }
    
    
    int orangesRotting(vector<vector<int>>& grid) {
        map<pair<int,int>, int>level;
        int ans = bfs(grid, level);
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }
        return ans;
    }