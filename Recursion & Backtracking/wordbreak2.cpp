#include<bits/stdc++.h>
using namespace std;

void solution(){

}
void wordHelper(string s, string move, vector<string> &ans, set<string> &st){
    //Base
    if(s.size() == 0){
        ans.push_back(move);
        return;
    }
    
    for(int i = 0; i < s.size(); i++){
        string left = s.substr(0, i + 1);
        if(st.find(left) != st.end()){
            string right = s.substr(i + 1, s.size() - i - 1);
            wordHelper(right, move + left + " ", ans, st);
        }
    }
}

vector<string> wordBreak(string &s, vector<string> &dictionary)
{
    vector<string>ans;
    set<string>st;
    for(string it : dictionary){
        st.insert(it);
    }
    wordHelper(s, "", ans, st);
    return ans;
    
}

int main(){
	int t;
	cin>>t;
	while(t--){
		solution();
	}
}