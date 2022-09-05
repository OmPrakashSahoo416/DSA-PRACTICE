#include<bits/stdc++.h>
using namespace std;

void solution(){

}
void recur(int ind, vector<int> v, vector<vector<int>> &ans){
        //Base
        if(ind == v.size()){
            ans.push_back(v);
            return;
        }
        
        
        for(int i = ind; i < v.size(); i++){
            swap(v[i], v[ind]);
            recur(ind + 1, v,ans);
            swap(v[i], v[ind]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        recur(0, nums, ans);
        return ans;
    }

int main(){
	int t;
	cin>>t;
	while(t--){
		solution();
	}
}