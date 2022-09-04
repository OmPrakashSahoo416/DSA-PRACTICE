#include<bits/stdc++.h>
using namespace std;

 void recur(int sum, int ind, int t, vector<int> &v, set<vector<int>> &s, vector<int> move){
    //base
    if(sum == t){
        s.insert(move);
        return;
    }
    if(sum > t){
        return;
    }
    if(ind == v.size())return;
    
    move.push_back(v[ind]);
    recur(sum + v[ind], ind, t, v, s, move);
    move.pop_back();
    recur(sum, ind + 1, t, v, s, move);
    
}
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<vector<int>>ans;
    set<vector<int>>s;
    vector<int> move;
    recur(0,0,target, candidates, s, move);
    for(auto it : s){
        ans.push_back(it);
    }
    return ans;
}
int main(){
	
}