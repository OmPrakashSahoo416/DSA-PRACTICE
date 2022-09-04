#include<bits/stdc++.h>
using namespace std;

vector<vector<string>> partition(string s) {
    vector<vector<string>>ans;
    vector<string> move;
    palindrome(0, s, move, ans);
    return ans;
}

bool isPalindrome(string s, int b, int e){
    string str = s.substr(b, e - b + 1);
    string s2 = str;
    reverse(str.begin(), str.end());
    if(str == s2){
        return true;
    }
    return false;
}
void palindrome(int ind, string s, vector<string> move, vector<vector<string>> &ans){
    //Base
    if(ind == s.size()){
        ans.push_back(move);
        return;
    }
    
    
    for(int i = ind; i < s.size(); i++){
        if(isPalindrome(s, ind, i)){
            move.push_back(s.substr(ind, i - ind + 1));
            palindrome(i + 1, s, move, ans);
            move.pop_back();
        }
    }
}
int main(){
	
}