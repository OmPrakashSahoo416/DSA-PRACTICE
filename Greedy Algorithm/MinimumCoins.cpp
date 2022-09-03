#include<bits/stdc++.h>
using namespace std;

int findMinimumCoins(int amount) 
{
    int count = 0;
    vector<int>coins = {1,2,5,10,20,50,100,500,1000};
    int ind = coins.size() - 1;
    while(amount != 0){
        if(amount < coins[ind]){
            ind--;
        }else{
            amount -= coins[ind];
            count++;
        }
    }
    return count;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		solution();
	}
}