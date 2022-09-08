#include<bits/stdc++.h>
using namespace std;


void solution(){
}

bool IsPossible(vector<int> &v, int st, int mid){
    int count = 0;
    int currSum = 0;
    for(int i = 0; i < v.size(); i++){
        if(currSum + v[i] <= mid){
            currSum += v[i];
        }else{
            count++;
            currSum = v[i];
            if(currSum > mid)return false;
        }
    }
    return count < st;
}
int books(vector<int> &A, int B) {
    int lo = A[0];
    int hi = 0;
    int n = A.size();
    if(n < B){
        return -1;
    }
    for(int i = 0; i < n; i++){
        hi += A[i];
        lo = min(lo, A[i]);
    }
    while(lo <= hi){
        int mid = (lo + hi) / 2;
        if(IsPossible(A, B, mid)){
            hi = mid - 1;
        }else{
            lo = mid + 1;
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