#include<bits/stdc++.h>
using namespace std;

void solution(){

}
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size();
    int m = nums2.size();
    if(n > m){
        return findMedianSortedArrays(nums2, nums1);
    }
    int lo = 0;
    int hi = n;
    while(lo <= hi){
        int c1 = (lo + hi) / 2;
        int c2 = (n + m + 1) / 2 - c1;
        
        int l1, l2, r1, r2;
        if(c1 == 0){
            l1 = INT_MIN;
        }else{
            l1 = nums1[c1 - 1];
        }
        
        if(c2 == 0){
            l2 = INT_MIN;
        }else{
            l2 = nums2[c2 - 1];
        }
        
        if(c1 == n){
            r1 = INT_MAX;
        }else{
            r1 = nums1[c1];
        }
        
        if(c2 == m){
            r2 = INT_MAX;
        }else{
            r2 = nums2[c2];
        }
        
        if(l1 <= r2 && l2 <= r1){
            if((n + m) % 2 == 1){
                return (double)max(l1, l2) * 1.00000;
            }else{
                return (double)(max(l1, l2) + min(r1, r2)) / 2.00000;
            }
        }
        else if(l1 > r2){
            hi = c1 - 1;
        }else{
            lo = c1 + 1;
        }
        
    }
    return 0.00000;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		solution();
	}
}