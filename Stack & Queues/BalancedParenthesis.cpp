#include<bits/stdc++.h>
using namespace std;

// void solution(){
// }
bool isValid(string s) {
    int n = s.size();
    stack<int>st;
    for(int i = 0; i < n; i++){
        if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
            st.push(s[i]);
        }else{
            if(s[i] == ')'){
                if(st.size() == 0)return false;
                if(st.top() == '('){
                    st.pop();
                }else{
                    return false;
                }
            }else if(s[i] == ']'){
                if(st.size() == 0)return false;
                if(st.top() == '['){
                    st.pop();
                }
                else{
                    return false;
                }
            }else{
                if(st.size() == 0)return false;
                if(st.top() == '{'){
                    st.pop();
                }else{
                    return false;
                }
            }
        }
    }
    if(st.size() == 0){
        return true;
    }else{
        return false;
    }
}

int main(){
	// int t;
	// cin>>t;
	// while(t--){
	// 	solution();
	// }
}