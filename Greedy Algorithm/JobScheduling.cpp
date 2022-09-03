#include<bits/stdc++.h>
using namespace std;

static bool cmp(Job a, Job b){
    return a.profit > b.profit;
}

vector<int> JobScheduling(Job arr[], int n) 
{ 
    sort(arr, arr + n, cmp);
    int maxDead = 0;
    for(int i = 0; i < n; i++){
        maxDead = max(maxDead, arr[i].dead);
    }
    int slot[maxDead];
    memset(slot, -1, sizeof(slot));
    int count = 0, maxProfit = 0;
    for(int i = 0; i < n; i++){
        for(int j = arr[i].dead - 1; j >= 0; j--){
            if(slot[j] == -1){
                slot[j] = i;
                count++;
                maxProfit += arr[i].profit;
                break;
            }
        }
    }
    return {count, maxProfit};
}

int main(){

}