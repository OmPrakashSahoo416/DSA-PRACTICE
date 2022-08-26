#include<bits/stdc++.h>
using namespace std;

void setZeroes(vector<vector<int>>& matrix) {
	int n = matrix.size();
	int m = matrix[0].size();
	int col = 1;
     for(int i = 0; i < n; i++){
		if(matrix[i][0] == 0)col = 0;
		for(int j = 1; j < m; j++){
			if(matrix[i][j] == 0){
				matrix[i][0] = 0;
				matrix[0][j] = 0;
			}
		}
	}  

	for(int i = n-1; i >= 0; i--){
		for(int j = m - 1; j > 0; j--){
			if(matrix[i][0] == 0 || matrix[0][j] == 0){
				matrix[i][j] = 0;
			}
		}
		if(col == 0){
			matrix[i][0] = 0;
		}
	} 
}

int main(){
	int n, m;
	cin>>n>>m;
	vector<int>v1(m,0);
	vector<vector<int>>v(n,v1);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin>>v[i][j];
		}
	}
	setZeroes(v);

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cout<<v[i][j]<<" ";
		}
		cout<<endl;
	}
}