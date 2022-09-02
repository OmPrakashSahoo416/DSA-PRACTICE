#include<bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    int ans = 1;
    int n = nums.size();
    for(int i = 0; i < n - 1; i++){
        if(nums[i] != nums[i + 1]){
            ans++;
        }
    }
    
    int ptr = 0;
    for(int i = 0; i < n - 1; i++){
        if(nums[i] != nums[i + 1]){
            nums[ptr] = nums[i];
            ptr++;
        }
    }
    nums[ptr] = nums[n - 1];
    return ans;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		solution();
	}
}