#include<bits/stdc++.h>
using namespace std;

double Pow(double x, int n){
	double ans = 1.00000;
	if(n == 1)return x;
	if(n == 0)return 1.00000;

	if(n % 2 == 0){
		double y = (x * x);
		ans = Pow(y, n / 2);
	}
	else{
		double y = (x * x);
		ans = Pow(y,n / 2) * x;
	}
	return ans;
}

double myPow(double x, int n) {
    double ans = 1.00000;
    bool flag = false;
    if(n < 0){
    	flag = true;
    }
    n = abs(n);

    ans = Pow(x, n);
    if(!flag){
    	return ans;
    }else{
    	double as = 1 / ans;
    	return as;
    }
}

int main(){
	double x;
	cin>>x;
	int n;
	cin>>n;
	double ans= myPow(x, n);
	cout<<fixed<<ans<<setprecision(5)<<endl;
}