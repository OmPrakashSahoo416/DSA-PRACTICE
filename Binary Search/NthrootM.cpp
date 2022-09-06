#include<bits/stdc++.h>
using namespace std;

void solution(){

}

double multiply(double a, int n){
    double ans = 1.0;
    for(int i = 0; i < n; i++){
        ans *= a;
    }
    return ans;
}

double findNthRootOfM(int n, int m) {
    double lo = 1;
    double hi = m;
    double diff = 0.00001;
    
    while(hi - lo > diff){
        double mid = (lo + mid) / 2.0;
        double val = multiply(mid, n);
        if(val < m){
            lo = mid;
        }else{
            hi = mid;
        }
    }
    return lo;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		solution();
	}
}