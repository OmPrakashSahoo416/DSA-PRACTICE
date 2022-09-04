#include<bits/stdc++.h>
using namespace std;

void recur(int sum, int ind, vector<int>&v, vector<int> &ans){
    if(ind == v.size())return;
    
    ans.push_back(sum + v[ind]);
    
    recur(sum + v[ind], ind + 1, v, ans);
    recur(sum, ind + 1, v, ans);
}

vector<int> subsetSums(vector<int> arr, int N)
{
    vector<int>ans;
    ans.push_back(0);
    recur(0,0,arr,ans);
    sort(ans.begin(), ans.end());
    return ans;
}
int main(){
	
}