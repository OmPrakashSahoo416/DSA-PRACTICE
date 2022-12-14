#include<bits/stdc++.h>
using namespace std;

void solution(){

}
int search(vector<int>& nums, int target) {
    int lo = 0;
    int hi = nums.size() - 1;
    while(lo <= hi){
        int mid = (lo + hi) / 2;
        if(nums[mid] == target){
            return mid;
        }
        else if(nums[lo] <= nums[mid]){
            if(target <= nums[mid] && target >= nums[lo]){
                hi = mid - 1;
            }else{
                lo = mid + 1;
            }
        }else{
            if(target >= nums[mid] && target <= nums[hi]){
                lo = mid + 1;
            }else{
                hi = mid - 1;
            }
        }
    }
    return -1;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		solution();
	}
}