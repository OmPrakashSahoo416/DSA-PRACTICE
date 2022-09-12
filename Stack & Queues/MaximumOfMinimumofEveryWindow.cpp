#include<bits/stdc++.h>
vector<int> maxMinWindow(vector<int> arr, int n) {
    vector<int> v1(n, -1), v2(n, n);
    stack<int> s;
    s.push(0);
    for(int i=1;i<n;i++) {
        while(s.size() > 0 && arr[s.top()] >= arr[i]) {
            s.pop();
        }
        if(s.size() > 0) {
            v1[i] = s.top();
        }
        s.push(i);
    }
    while(s.size()) {
        s.pop();
    }
    s.push(n-1);
    for(int i=n-2;i>=0;i--) {
        while(s.size() > 0 && arr[s.top()] >= arr[i]) {
            s.pop();
        }
        if(s.size() > 0) {
            v2[i] = s.top();
        }
        s.push(i);
    }
    vector<int> v(n, INT_MIN);
    for(int i=0;i<n;i++) {
        int size = v2[i] - v1[i] - 1;
        v[size-1] = max(v[size-1], arr[i]);
    }
    vector<int> ans(n);
    int curr = INT_MIN;
    for(int i=n-1;i>=0;i--) {
        curr = max(curr, v[i]);
        ans[i] = curr;
    }
    return ans; 
}