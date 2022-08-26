#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> generate(int numRows) {
	vector<vector<int>>ans;
	for(int i = 0; i < numRows; i++){
		vector<int>v(i + 1, -1);
		v[0] = v[i] = 1;
		for(int j = 1; j < i; j++){
			if(v[j] == -1){
				v[j] = ans[i - 1][j] + ans[i - 1][j - 1];
			}
		}
		ans.push_back(v);
	}
	return ans;
}

int main(){
	int n;
	cin>>n;
	vector<vector<int>> ans = generate(n);
	for(int i = 0; i < ans.size(); i++){
		for(int j = 0; j < ans[i].size(); j++){
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}

}