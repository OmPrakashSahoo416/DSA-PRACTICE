#include<bits/stdc++.h>
using namespace std;

// void solution(){
// }
class MyStack {
    queue<int>q;
public:
    MyStack() {
        
        
    }
    
    void push(int x) {
        q.push(x);
        int sz = q.size();
        for(int i = 0; i < sz - 1; i++){
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int x = q.front();
        q.pop();
        return x;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.size() == 0;
    }
};

int main(){
	// int t;
	// cin>>t;
	// while(t--){
	// 	solution();
	// }
}