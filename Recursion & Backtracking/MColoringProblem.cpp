#include<bits/stdc++.h>
using namespace std;

void solution(){

}
bool isValid(int node, int col, bool graph[101][101], int color[], int m){
    for(int i = 0; i < m; i++){
        if(i != node && graph[i][node] == 1 && color[i] == col){
            return false;
        }
    }
    return true;
}


bool recur(int node, bool graph[101][101], int m, int n, int color[]){
    //Base
    if(node == n)return true;
    
    for(int i = 1; i <= m; i++){
        if(isValid(node, i, graph, color, n)){
            color[node] = i;
            if(recur(node + 1, graph, m, n, color))return true;
            color[node] = 0;
        }
    }
    return false;
}
bool graphColoring(bool graph[101][101], int m, int n) {
    int color[n] = {0};
    if(recur(0, graph, m, n, color))return true;
    return false;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		solution();
	}
}