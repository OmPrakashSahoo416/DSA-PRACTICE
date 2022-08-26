#include<bits/stdc++.h>
using namespace std;

void nextPermutation(vector<int>& nums) {
	int n = nums.size();
	int ind1 = -1;
	int ind2 = -1;
	for(int i = n - 1; i > 0; i--){
		if(nums[i - 1] < nums[i]){
			ind1 = i - 1;
			break;
		}
	}
	if(ind1 != -1){

		for(int i = n - 1; i > 0; i--){
			if(nums[i] > nums[ind1]){
				swap(nums[ind1], nums[i]);
				break;
			}
		}
		reverse(nums.begin() + ind1 + 1, nums.end());
	}
	else{
		reverse(nums.begin(), nums.end());
	}
}

int main(){
	int n;
	cin>>n;
	vector<int>v(n);
	for(int i = 0; i < n; i++){
		cin>>v[i];
	}
	nextPermutation(v);
	for(int i = 0; i < n; i++){
		cout<<v[i]<<" ";
	}
}