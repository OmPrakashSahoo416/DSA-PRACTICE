#include<bits/stdc++.h>
using namespace std;

void solution(){

}
int kthElement(int arr1[], int arr2[], int n, int m, int k)
{
    if(n > m){
        return kthElement(arr2, arr1, m, n,k);
    }
    int lo = max(0, k - m);
    int hi = min(k, n);
    while(lo <= hi){
        int c1 = (lo + hi) / 2;
        int c2 = k - c1;
        int l1, l2, r1, r2;
        if(c1 == 0){
            l1 = INT_MIN;
        }else{
            l1 = arr1[c1 - 1];
        }
        
        if(c2 == 0){
            l2 = INT_MIN;
        }else{
            l2 = arr2[c2 - 1];
        }
        
        if(c1 == n){
            r1 = INT_MAX;
        }else{
            r1 = arr1[c1];
        }
        
        if(c2 == m){
            r2 = INT_MAX;
        }else{
            r2 = arr2[c2];
        }
        
        if(l1 <= r2 && l2 <= r1){
            return max(l1, l2);
        }
        else if(l1 > r2){
            hi = c1 - 1;
        }else{
            lo = c1 + 1;
        }
        
    }
    return -1;
    
}

int main(){
	int t;
	cin>>t;
	while(t--){
		solution();
	}
}