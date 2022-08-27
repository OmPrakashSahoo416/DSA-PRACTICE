#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {
	sort(intervals.begin(), intervals.end());
    int n = intervals.size();
    vector<vector<int>> ans;
    ans.push_back({intervals[0][0], intervals[0][1]});
    int ind = 0;
    for(int i = 1; i < n; i++){
    	int a = intervals[i][0];
    	int b = intervals[i][1];
    	if(a <= ans[ind][1]){
    		ans[ind][1] = max(b, ans[ind][1]);
    	}else{
    		ans.push_back({a,b});
    		ind++;
    	}
    }
    return ans;
}

int main(){
	int n;
	cin>>n;
	vector<int>v2(2);
	vector<vector<int>>v(n,v2);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < 2; j++){
			cin>>v[i][j];
		}
	}
	vector<vector<int>> ans = merge(v);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < 2; j++){
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}
}