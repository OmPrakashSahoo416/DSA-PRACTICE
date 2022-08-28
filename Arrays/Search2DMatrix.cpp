#include<bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
	int n = matrix.size();
    int m = matrix[0].size();
    int row = 0;
    for(int i = 0; i < n; i++){
        if(matrix[i][0] <= target && matrix[i][m - 1] >= target){
            row = i;
            break;
        }
    }
    int lo = 0;
    int hi = m - 1;
    bool flag = false;
    while(lo < hi){
        int mid = (lo + hi) / 2;
        if(matrix[row][mid] == target){
            flag = true;
            break;
        }
        else if(matrix[row][mid] < target){
            lo++;
        }
        else{
            hi--;
        }
    }
    if(matrix[row][lo] == target || matrix[row][hi] == target){
        flag = true;
    }
    return flag;
}

int main(){
	int n, m, target;
	cin>>n>>m;
	cin>>target;
	vector<int>v2(m);
	vector<vector<int>>v(n,v2);
	for(int i = 0; i < n; i++){
		for(int i = 0; i < m; i++){
			cin>>v[i];
		}
	}
	cout<<searchMatrix(v, target)<<endl;
	
}