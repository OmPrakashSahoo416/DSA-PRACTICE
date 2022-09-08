#include<bits/stdc++.h>
using namespace std;

void solution(){
}
int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int>pq;
    int n = nums.size();
    for(int i = 0; i < n; i++){
        pq.push(nums[i]);
    }
    int ans;
    while(k--){
        ans = pq.top();
        pq.pop();
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