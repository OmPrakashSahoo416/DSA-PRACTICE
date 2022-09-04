#include<bits/stdc++.h>
using namespace std;

void recur(int ind, int t, vector<int>move, vector<vector<int>> &ans, vector<int> &v){
    if(t == 0){
        ans.push_back(move);
        return;
    }
    
    for(int i = ind; i < v.size(); i++){
        if(i > ind && v[i] == v[i-1])continue;
        if(v[i] > t)break;
        move.push_back(v[i]);
        recur(i + 1, t - v[i], move, ans, v);
        move.pop_back();
    }
}
vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int>>ans;
    vector<int>move;
    sort(candidates.begin(), candidates.end());
    recur(0, target, move, ans, candidates);
    
    return ans;
}
int main(){
	
}