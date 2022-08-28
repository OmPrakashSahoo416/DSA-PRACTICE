#include<bits/stdc++.h>
using namespace std;

int majorityElement(vector<int>& nums) {
     pair<int,int>ans;
     int n = nums.size();
     ans = {nums[0], 1};
     for(int i = 1; i < n; i++){
     	if(ans.first == nums[i]){
     		ans.second++;
     	}else{
     		ans.second--;
     		if(ans.second < 0){
     			ans = {nums[i], 1};
     		}
     	}
     }
     return ans.first;   
}

int main(){
	int n;
	cin>>n;
	vector<int>v(n);
	for(int i = 0; i < n; i++){
		cin>>v[i];
	}
	cout<<majorityElement(v)<<endl;
}