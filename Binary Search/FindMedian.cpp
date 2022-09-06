#include<bits/stdc++.h>
using namespace std;

void solution(){

}

int countless(int mid, vector<int> &row){
    int ans = 0;
    for(int i = 0; i < row.size(); i++){
        if(row[i] <= mid){
            ans++;
        }
    }
    return ans;
}
int findMedian(vector<vector<int> > &A) {
    int n = A.size();
    int m = A[0].size();
    int lo = 1;
    int hi = 1e9;
    
    while(lo <= hi){
        int mid = (lo + hi) / 2;
        int ct = 0;
        
        for(int i = 0; i < A.size(); i++){
            ct += countless(mid, A[i]);
        }
        if(ct <= (n * m) / 2){
            lo = mid + 1;
        }
        else{
            hi = mid - 1;
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