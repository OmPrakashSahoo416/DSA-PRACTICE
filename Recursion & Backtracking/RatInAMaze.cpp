#include<bits/stdc++.h>
using namespace std;

void solution(){

}
void recur(int i, int j, string move, vector<string> &ans, vector<vector<int>> &m
, vector<vector<int>> &visited){
    //Base
    if(i == m.size() - 1 && j == m.size() - 1){
        ans.push_back(move);
        return;
    }
    
    
    //DLRU Lexographical order
    if(i + 1 < m.size() && visited[i + 1][j] != 1 && m[i + 1][j] == 1){
        visited[i][j] = 1;
        recur(i + 1, j, move + 'D', ans, m, visited);
        visited[i][j] = 0;
    }
    
    if(j - 1 >= 0 && visited[i][j - 1] != 1 && m[i][j - 1] == 1){
        visited[i][j] = 1;
        recur(i, j - 1, move + 'L', ans, m, visited);
        visited[i][j] = 0;
    }
    
    if(j + 1 < m.size() && visited[i][j + 1] != 1 && m[i][j + 1] == 1){
        visited[i][j] = 1;
        recur(i, j + 1, move + 'R', ans, m, visited);
        visited[i][j] = 0;
    }
    
    if(i - 1 >= 0 && visited[i - 1][j] != 1 && m[i - 1][j] == 1){
        visited[i][j] = 1;
        recur(i - 1, j, move + 'U', ans, m, visited);
        visited[i][j] = 0;
    }
    
    
    
    
    
}


vector<string> findPath(vector<vector<int>> &m, int n) {
    vector<string>ans;
    vector<vector<int>>visited(n, vector<int>(n,0));
    if(m[0][0] == 1){
        recur(0,0,"",ans,m,visited);
    }
    return ans;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		solution();
	}
}