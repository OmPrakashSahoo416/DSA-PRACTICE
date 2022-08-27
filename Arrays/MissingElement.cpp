#include<bits/stdc++.h>
using namespace std;

int findDuplicate(vector<int>& nums) {
    int n = nums.size();
    int ans = 0;
    int ind = 0;
    while(true){
    	int x = ind;
    	ind = nums[x];
    	if(nums[x] == -1){
    		ans = x;
    		break;
    	}else{
    		nums[x] = -1;
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
	cout<<findDuplicate(v);
}