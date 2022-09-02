#include<bits/stdc++.h>
using namespace std;

int findMaxConsecutiveOnes(vector<int>& nums) {
    int n = nums.size();
    int ans = 0;
    int sum = 0;
    for(int i = 0 ; i < n; i++){
        if(nums[i] == 1){
            sum++;
        }else{
            ans = max(sum, ans);
            sum = 0;
            
        }
    }
    ans = max(ans, sum);
    return ans;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		solution();
	}
}