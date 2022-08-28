#include<bits/stdc++.h>
using namespace std;

vector<int> majorityElement(vector<int>& nums) {
	int n = nums.size();
	int n1 = -1, n2 = -1, c1 = 0, c2 = 0;
	for(int i = 0; i < n; i++){
		if(n1 == nums[i]){
			c1++;
		}
		else if(n2 == nums[i]){
			c2++;
		}
		else if(c1 == 0){
			n1 = nums[i];
			c1 = 1;
		}else if(c2 == 0){
			n2 = nums[i];
			c2 = 1;
		}
		else{
			c1--;
			c2--;
		}
	}
	c1 = 0, c2 = 0;
	for(int i = 0; i < n; i++){
		if(nums[i] == n1){
			c1++;
		}
		if(nums[i] == n2){
			c2++;
		}
	}
	vector<int>ans;
	if(c1 >= n/3 + 1){
		ans.push_back(n1);
	}
	if(c2 >= n/3 + 1){
		ans.push_back(n2);
	}
	if(ans.size() == 2){
		if(n1 == n2){
			ans.pop_back();
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
	vector<int>ans = majorityElement(v);
	if(ans.size() == 2){
		cout<<ans[0]<<" "<<ans[1]<<endl;
	}else{
		cout<<ans[0]<<endl;
	}
}