#include<bits/stdc++.h>
using namespace std;

void solution(){

}

bool isValid(char k, int row, int col, vector<vector<char>>& board){
    for(int i = 0; i < 9; i++){
        if(board[i][col] == k){
            return false;
        }
        if(board[row][i] == k){
            return false;
        }
        if(board[(3 * (row / 3)) + i / 3][(3 * (col / 3)) + i % 3] == k){
            return false;
        }
    }
    return true;
    
}

bool solver(vector<vector<char>>&board){
    //Base
    
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            if(board[i][j] == '.'){
                for(char k = '1'; k <= '9'; k++){
                    if(isValid(k, i, j, board)){
                        board[i][j] = k;
                        if(solver(board)){
                            return true;
                        }
                        board[i][j] = '.';
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void solveSudoku(vector<vector<char>>& board) {
    solver(board);
}

int main(){
	int t;
	cin>>t;
	while(t--){
		solution();
	}
}