#include<bits/stdc++.h>
using namespace std;

int dp[101][101];

bool IsValid(int i, int j, int m, int n){
	return (i >= 0 && j >= 0 && i < m && j < n);
}

int pathCount(int i, int j, int m, int n){
	//Base
	if(dp[i][j] != -1)return dp[i][j];
	if(i == m - 1 && j == n - 1){
		return 0;
	}
	if(!IsValid(i, j, m, n)){
		return -1;
	}
	int a = pathCount(i + 1, j, m, n);
	int b = pathCount(i, j + 1, m, n);

	return dp[i][j] = a + b + 1;
}

int uniquePaths(int m, int n) {
	memset(dp, -1, sizeof(dp));
    return 1 + pathCount(0, 0, m, n);
}

int main(){
	int m, n;
	cin>>m>>n;
	cout<<uniquePaths(m,n)<<endl;
}