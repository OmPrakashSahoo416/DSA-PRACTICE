#include<bits/stdc++.h>
using namespace std;

void solution(){

}

bool isValid(int row, int col, int n, vector<string> board){
    int r = 0;
    int c = 0;
    
    while(c < col){
        if(board[row][c++] == 'Q')return false;
    }
    r = row;
    c = col;
    
    while(r != -1 && c != -1){
        if(board[r--][c--] == 'Q'){
            return false;
        }
        
    }
    r = row;
    c = col;
    
    while(r != n && c != -1){
        if(board[r++][c--] == 'Q'){
            return false;
        }  
    }
    return true;
}

void recur(int c, vector<string>board, int n, vector<vector<string>> &ans){
    //Base
    if(c == n){
        ans.push_back(board);
        return;
    }
    
    
    for(int i = 0; i < n; i++){
        if(isValid(i,c,n,board)){
            board[i][c] = 'Q';
            recur(c + 1, board, n, ans);
            board[i][c] = '.';
        }
    }
    
}
vector<vector<string>> solveNQueens(int n) {
    string s(n,'.');
    vector<string>v(n,s);
    vector<vector<string>> ans;
    recur(0, v, n, ans);
    return ans;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		solution();
	}
}