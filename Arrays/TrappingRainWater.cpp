#include<bits/stdc++.h>
using namespace std;

int trap(vector<int>& height) {
    int ans = 0;
    int n = height.size();
    int maxl = 0;
    int maxr = 0;
    int l = 0, r = n - 1;
    
    while(l <= r){
        if(height[l] <= height[r]){
            if(height[l] > maxl)maxl = height[l];
            else ans += (maxl - height[l]);
            l++;
        }else{
            if(height[r] > maxr)maxr = height[r];
            else ans += (maxr - height[r]);
            r--;
        }
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