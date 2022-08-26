#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices) {
	int n = prices.size();
    int mnl = prices[0];
    int ans = 0;
    for(int i = 0; i < n; i++){
    	mnl = min(mnl, prices[i]);
    	ans = max(ans, prices[i] - mnl);
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
	cout<<maxProfit(v)<<endl;

}