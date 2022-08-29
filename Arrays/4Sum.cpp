#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
	int n = nums.size();
    set<vector<int>>s;
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    for(int i = 0; i < n; i++){
    	for(int j = i + 1; j < n; j++){
    		long long x = nums[i] + nums[j];
    		long long t = target - x;
    		int lo = j + 1;
    		int hi = n - 1;
    		while(lo < hi){
    			long long y = nums[lo] + nums[hi];
    			if(y == t){
    				vector<int>v = {nums[i], nums[j], nums[lo], nums[hi]};
    				s.insert(v);
    				lo++;
    				hi--;
    			}
    			else if(y < t){
    				lo++;
    			}else{
    				hi--;
    			}
    		}
    	}
    }
    for(auto it : s){
    	vector<int>as;
    	for(auto i : it){
    		as.push_back(i);
    	}
    	ans.push_back(as);
    }
    return ans;

}

int main(){
	int n;
	cin>>n;
	int t;
	cin>>t;
	vector<int>v(n);
	for(int i = 0; i < n; i++){
		cin>>v[i];
	}
	vector<vector<int>> ans = fourSum(v, t);
	for(auto it : ans){
		for(auto i : it){
			cout<<i<<" ";
		}
		cout<<endl;
	}
}