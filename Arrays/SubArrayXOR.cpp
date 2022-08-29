#include<bits/stdc++.h>
using namespace std;

int subarraysXor(vector<int> &arr, int x){
    int n = arr.size();
    int pref = 0;
    int ans = 0;
    map<int,int>mp;
    for(int i = 0; i < n; i++){
    	pref = (pref ^ arr[i]);
    	if(pref == x)ans++;
    	int a = (pref ^ x);
    	if(mp.find(a) != mp.end()){
    		ans += mp[a];
    	}
    	mp[pref]++;
    }
    return ans;
}

int main(){
	int n;
	cin>>n;
	int x;
	cin>>x;
	vector<int>v(n);
	for(int i = 0; i < n; i++){
		cin >> v[i];
	}
	cout<<subarraysXor(v, x);
}