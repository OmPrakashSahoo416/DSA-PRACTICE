#include<bits/stdc++.h>
using namespace std;

pair<int,int> missingAndRepeating(vector<int> &arr, int n){
	long long ans = 0;
	long long x = 0;
	pair<int,int>as;
	for(int i = 0; i < n; i++){
		ans = (ans ^ arr[i]);
	}
	for(int i = 1; i <= n; i++){
		x = (x ^ i);
	}
	ans = (ans ^ x);
	int gg = 0;
	// cout<<ans<<" ";
	int ind = 0;
	while(ans / 2 != 0){
		if((ans & 1) == 1){
			gg = ind;
		}
		ans = ans / 2;
		ind++;
	}
	gg = ind;
	// cout<<gg<<" ";

	long long a1 = 0, a2 = 0;
	long long a3 = 0, a4 = 0;
	for(int i = 0; i < n; i++){
		int l = (arr[i] >> gg);
		if(l % 2 == 1){
			a1 = (a1 ^ arr[i]);
		}else{
			a2 = (a2 ^ arr[i]);
		}
	}
	for(int i = 1; i <= n; i++){
		int l = (i >> gg);
		if(l % 2 == 1){
			a3 = (a3 ^ i);
		}else{
			a4 = (a4 ^ i);
		}
	}
	a1 = (a1 ^ a3);
	a2 = (a2 ^ a4);
	bool flag = true;
	for(int i = 0; i < n; i++){
		if(a1 == arr[i]){
			flag = false;
			break;
		}
	}
	if(!flag){
		swap(a1,a2);
	}
	as = {a1,a2};
	return as;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int>v(n);
		for(int i = 0; i < n; i++){
			cin>>v[i];
		}
		pair<int,int>ans = missingAndRepeating(v, n);
		cout<<ans.first<<" "<<ans.second<<endl;
	}
	
}