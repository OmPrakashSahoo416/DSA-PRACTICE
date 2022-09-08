#include<bits/stdc++.h>
using namespace std;

// void solution(){
// }
vector<int> Solution::solve(vector<int> &A, vector<int> &B, int C) {
    vector<int>ans;
    set<pair<int, pair<int,int>>>s;
    priority_queue<pair<int, pair<int,int>>>pq;
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    int n = A.size();
    pq.push({A[n - 1] + B[n - 1],{n - 1, n - 1}});//sum,{i,j};
    while(!pq.empty()){
        int sum = pq.top().first;
        int i = pq.top().second.first;
        int j = pq.top().second.second;
        if(ans.size() < C){
            ans.push_back(sum);
            if(ans.size() == C){
                break;
            }
        }
        pq.pop();
        if(i - 1 >= 0){
            if(s.find({A[i - 1] + B[j], {i - 1, j}}) == s.end()){
                pq.push({A[i - 1] + B[j], {i - 1, j}});
            }
            s.insert({A[i - 1] + B[j], {i - 1, j}});
        }
        if(j - 1 >= 0){
            if(s.find({A[i] + B[j - 1], {i, j - 1}}) == s.end()){
                pq.push({A[i] + B[j - 1], {i, j - 1}});
            }
            s.insert({A[i] + B[j - 1], {i, j - 1}});
        }
        
    }
    return ans;
}

int main(){
	// int t;
	// cin>>t;
	// while(t--){
	// 	solution();
	// }
}