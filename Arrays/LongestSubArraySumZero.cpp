#include<bits/stdc++.h>
using namespace std;

int maxLen(vector<int>&A, int n){   
    map<int,int>mp;
    int ans = 0;
    int sum = 0;
    for(int i = 0; i < n; i++){
    	sum += A[i];
    	if(sum == 0){
    		ans = max(ans, i + 1);
    	}
    	if(mp.find(sum) != mp.end()){
    		ans = max(ans, i - mp[sum]);
    	}else{
    		mp[sum] = i;
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
	cout<<maxLen(v, n);
}