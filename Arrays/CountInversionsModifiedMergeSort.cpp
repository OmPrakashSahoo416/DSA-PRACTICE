#include<bits/stdc++.h>
using namespace std;


long long merge(int lo, int mid, int hi, vector<long long> &arr, vector<long long>temp){
	long long ans = 0;
	int i = lo, j = mid, k = hi;
	int ind = lo;
	while(i <= mid - 1 && j <= hi){
		if(arr[i] > arr[j]){
			temp[ind++] = arr[j++];
			ans += (mid - i);
		}else{
			temp[ind++] = arr[i++]; 
		}
	}

	while(i <= mid - 1){
		temp[ind++] = arr[i++];
	}
	while(j <= hi){
		temp[ind++] = arr[j++];
	}
	for(int ij = lo; ij <= hi; ij++){
		arr[ij] = temp[ij];
	}
	return ans;
}

long long mergeSort(int lo, int hi, vector<long long> &arr, vector<long long>temp){
	long long ans = 0;
	if(lo < hi){
    	int mid = (hi + lo) / 2;
    	ans += mergeSort(lo, mid, arr, temp);
    	ans += mergeSort(mid + 1, hi, arr, temp);
    	ans += merge(lo, mid + 1, hi, arr, temp);
    }
    return ans;
}

long long getInversions(vector<long long> &arr, int n){
    long long ans = 0;
    vector<long long>temp(n);
    ans += mergeSort(0, n - 1, arr, temp);
    return ans;
}

int main(){
	int t = 1;
	// cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<long long>v(n);
		for(int i = 0; i < n; i++){
			cin>>v[i];
		}
		long long ans = getInversions(v, n);
		cout<<ans<<endl;
	}
	
}