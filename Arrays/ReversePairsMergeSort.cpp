#include<bits/stdc++.h>
using namespace std;

int merge(int lo, int mid, int hi, vector<int> &v, vector<int> temp){
	int i = lo;
	int j = hi;
	int k = mid;
	int ans = 0;

	for(int a = lo; a <= mid - 1; a++){
		while(k <= hi && v[a] > 2 * v[k]){
			k++;
		}
		ans += (k - mid);
	}



	k = mid;
	int ind = lo;
	while(i <= mid - 1 &&  k <= hi ){
		if(v[i] <= v[k]){
			temp[ind++] = v[i++];
		}else{
			temp[ind++] = v[k++];
		}
	}
	while(i <= mid - 1){
		temp[ind++] = v[i++];
	}
	while(k <= hi){
		temp[ind++] = v[k++];
	}
	for(i = lo; i <= hi; i++){
		v[i] = temp[i];
	}
	return ans;
}


int mergesort(int lo, int hi, vector<int> &v, vector<int> temp){
	int ans = 0;
	if(lo < hi){
		int mid = (hi + lo) / 2;

		ans += mergesort(lo, mid, v, temp);
		ans += mergesort(mid + 1, hi, v, temp);
		ans += merge(lo, mid + 1, hi, v, temp);
	}
	return ans;
}


int reversePairs(vector<int>& nums) {
    int n = nums.size();
    vector<int>temp(n);
    int ans = mergesort(0, n-1, nums, temp);
    return ans;
}

int main(){
	int n;
	cin>>n;
	vector<int>v(n);
	for(int i = 0; i < n; i++){
		cin>>v[i];
	}
	cout<<reversePairs(v);
}