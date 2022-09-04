#include<bits/stdc++.h>
using namespace std;

void recur(vector<int>move, int ind, vector<int> &v, set<vector<int>> &s){
    //Base
    if(ind == v.size())return;
    s.insert(move);
    move.push_back(v[ind]);
    s.insert(move);
    recur(move, ind + 1, v, s);
    move.pop_back();
    recur(move,ind + 1, v, s);
} 


vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    set<vector<int>>s;
    vector<int>move;
    sort(nums.begin(), nums.end());
    recur(move, 0, nums, s);
    vector<vector<int>>ans;
    for(auto it : s){
        ans.push_back(it);
    }
    return ans;
}
int main(){
	
}