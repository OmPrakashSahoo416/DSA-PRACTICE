#include<bits/stdc++.h>
using namespace std;

// void solution(){
// }
 vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>ans;
        map<int,int>mp;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            mp[nums[i]]++;
        }
        vector<pair<int,int>>vp;
        for(auto it : mp){
            vp.push_back({it.second, it.first});
        }
        sort(vp.begin(), vp.end());
        reverse(vp.begin(), vp.end());
        int ind = 0;
        while(k--){
            ans.push_back(vp[ind++].second);
        }
        return ans;
    }

int main(){
	// int t;
	// cin>>t;
	// while(t--){
	// 	solution();
	// }
}