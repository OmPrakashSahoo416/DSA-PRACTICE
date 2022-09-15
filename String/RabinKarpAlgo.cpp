#include<bits/stdc++.h>
using namespace std;

int rabinKarp(string &a, string &b){
	int ans = 0;
	int m = b.size();
	int n = a.size();
	int ind = 0;
	long long val = 0; // Value of string 2.
	for(int i = m - 1; i >= 0; i--){
		val += (pow(10, ind) * (b[i] - 'A'));
		ind++;
	}
	long long currVal = 0;
	for(int i = 0; i < m; i++){
		currVal += (pow(10,i) * (a[m - 1 - i] - 'A'));
	}
	ind = 0;
	for(int i = m; i < n; i++){
		if(currVal == val){
			cout<<ind<<" ";
			ans++;
		}
		currVal  = ((currVal - (pow(10,m - 1) * (a[ind] - 'A'))) * 10) + (a[i] - 'A');
		ind++;
	}
	if(currVal == val)ans++;
	return ans;
}

void solution(){
	string s1, s2;
	cin>>s1>>s2;
	cout<<rabinKarp(s1, s2)<<endl;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		solution();
	}
}