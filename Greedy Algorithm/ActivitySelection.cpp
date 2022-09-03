#include<bits/stdc++.h>
using namespace std;

bool cmp(vector<int>a, vector<int>b){
    if(a[1] < b[1])return true;
    else if(a[1] > b[1])return false;
    else if(a[2] < b[2])return true;
    else return false;
}

int maximumActivities(vector<int> &start, vector<int> &finish) {
    int ans = 0;
    vector<int>v2(3);
    int n = start.size();
    vector<vector<int>>v(n, v2);
    for(int i = 0; i < n; i++){
        v[i] = {start[i], finish[i], i};
    }
    sort(v.begin(), v.end(), cmp);
    int end = v[0][1];
    for(int i = 1; i < n; i++){
        if(v[i][1] > end){
            ans++;
            end = v[i][1];
        }
    }
    return ans;
}

int main(){
	vector<int>v1 = {1,1,1};
	vector<int>v2 = {4,5,9};

	cout<<maximumActivities(v1, v2);
}