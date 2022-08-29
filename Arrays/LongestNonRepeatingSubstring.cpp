#include<bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s) {
    int len = 1;
    int n = s.size();
    map<char, int>mp;
    if(n == 0)return 0;
    if(n == 1)return 1;
    int fi = 0;
    for(int i = 0; i < n; i++){
        if(mp.find(s[i]) != mp.end()){
        	int l = mp[s[i]];
            fi = l + 1;
            len = max(len, i - l - 1);
            mp.erase(s[i]);
            mp[s[i]] = i;
        }else{
            mp[s[i]] = i;
            len = max(len, i - fi + 1);
        }
        cout<<fi<<" ";
    }
    return len;
}
int main(){
	string s;
	cin>>s;
	cout<<lengthOfLongestSubstring(s);
}