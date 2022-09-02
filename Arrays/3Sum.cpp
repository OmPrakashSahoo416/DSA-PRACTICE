#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int n = nums.size();
        set<vector<int>>s;
        for(int i = 0; i < n - 2; i++){
            int lo = i + 1;
            int hi = n - 1;
            int target = 0 - (nums[i]);
            while(lo < hi){
                if(nums[lo] + nums[hi] == target){
                    s.insert({nums[i], nums [lo++], nums[hi--]});
                }
                else if(nums[lo] + nums[hi] < target){
                    lo++;
                }else{
                    hi--;
                }
            }
        }
        for(auto it : s){
            ans.push_back(it);
        }
        return ans;
    }

int main(){
	int t;
	cin>>t;
	while(t--){
		solution();
	}
}