#include<bits/stdc++.h>
using namespace std;

void sortColors(vector<int>& nums) {
    int ct0 = 0, ct1 = 0, ct2 = 0;
    int n = nums.size();
    for(int i = 0; i < n; i++){
    	if(nums[i] == 0)ct0++;
    	if(nums[i] == 1)ct1++;
    	if(nums[i] == 2)ct2++;
    }
    int f0 = 0, f1 = f0 + ct0, f2 = f1 + ct1;

    for(int i = 0; i < n; i++){
    	if(i >= f0 && i < f1){
    		nums[i] = 0;
    	}
    	if(i >= f1 && i < f2){
    		nums[i] = 1;
    	}
    	if(i >= f2 ){
    		nums[i] = 2;
    	}
    }

}

int main(){
	int n;
	cin>>n;
	vector<int>v(n);
	for(int i = 0; i < n; i++){
		cin>>v[i];
	}
	sortColors(v);
	for(int i = 0; i < n; i++){
		cout<<v[i]<<" ";
	}

}