#include<bits/stdc++.h>
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
	if(m == 0){
            nums1 = nums2;
            return;
        }
        if(n == 0){
            return;
        }
        for(int i = m; i < n + m; i++){
            nums1[i] = nums2[i - m];
        }
        sort(nums1.begin(), nums1.end());
}

int main(){
	int n, m;
	cin>>n>>m;
	vector<int>v(n + m, 0);
	vector<int>v2(m);
	for(int i = 0; i < n; i++){
		int a;
		cin>>a;
		v[i] = a;
	}
	for(int i = 0; i < m; i++){
		cin>>v2[i];
	}
	merge(v, m, v2, n);
	for(int i = 0; i < n + m; i++){
		cout<<v[i]<<" ";
	}
	
}