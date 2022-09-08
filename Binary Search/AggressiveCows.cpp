#include<bits/stdc++.h>
using namespace std;

bool canPlace(vector<int> &v, int minDist, int cow){
	int ls = -1;
	int cows = cow;
	for(int i = 0; i < v.size(); i++){
		if(v[i] - ls >= minDist || ls == -1){
			ls = v[i];
			cows--;
		}
		if(cows == 0){
			return true;
		}
	}
	return false;
}

void solution(){
	int n;
	int c;
	cin>>n>>c;
	vector<int>v(n);
	for(int i = 0; i < n; i++){
		cin>>v[i];
	}
	sort(v.begin(), v.end());
	int lo = 0, hi = 1e9;
	while(hi - lo > 1){
		int mid = (lo + hi) / 2;

		if(canPlace(v, mid, c)){
			lo = mid;
		}else{
			hi = mid - 1;
		}
	}
	if(canPlace(v, hi, c)){
		cout<<hi<<endl;
	}else{
		cout<<lo<<endl;
	}

}


int main(){
	int t;
	cin>>t;
	while(t--){
		solution();
	}
}