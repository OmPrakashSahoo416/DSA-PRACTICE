#include<bits/stdc++.h>
using namespace std;

int dp[100005];

int dpfunc(int ind, vector<int>& nums){
	int n = nums.size();
    
    if(dp[ind] != -1){
    	return dp[ind];
    }
    int ans = 1;
    for(int i = 0; i < n; i++){
    	if(nums[i] == 1 + nums[ind]){
    		ans = max(ans, 1 + dpfunc(i, nums));
    	}
    }
    return dp[ind] = ans;
}

int longestConsecutive(vector<int>& nums) {
	memset(dp, -1, sizeof(dp));
	int ans = 0;
    for(int i = 0; i < nums.size(); i++){
		ans = max(ans, dpfunc(i, nums));
	}
	return ans;
}

int main(){
	int n;
	cin>>n;
	vector<int>v(n);
	for(int i = 0; i < n; i++){
		cin>>v[i];
	}
	int ans = longestConsecutive(v);	
	cout<<ans<<endl;
}