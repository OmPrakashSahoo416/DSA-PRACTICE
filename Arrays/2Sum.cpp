#include<bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    int n = nums.size();
    vector<pair<int,int>>v;
    for(int i = 0; i < n; i++){
        v.push_back({nums[i],i});
    }
    sort(v.begin(), v.end());
    int lo = 0;
    int hi = n - 1;
    vector<int>ans;
    while(lo < hi){
        if(v[lo].first + v[hi].first == target){
            ans = {v[lo].second, v[hi].second};
            break;
        }
        else if(v[lo].first + v[hi].first < target){
            lo++;
        }else{
            hi--;
        }
    }
    return ans;
}

int main(){
	int n;
	cin>>n;
	int t;
	cin>>t;
	vector<int>v(n);
	for(int i = 0; i  <n; i++){
		cin>>v[i];
	}
	vector<int>ans = twoSum(v, t);
	for(auto it : ans){
		cout<<it<<" ";
	}
}