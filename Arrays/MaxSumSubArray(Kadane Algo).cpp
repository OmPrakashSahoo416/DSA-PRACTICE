#include<bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int>& nums) {
	int n = nums.size();
	int sum = 0;
	int ans = INT_MIN;
	for(int i = 0; i < n; i++){
		sum += nums[i];
		ans = max(ans, sum);
		if(sum < 0){
			sum = 0;
		}
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
	cout<<maxSubArray(v);
}