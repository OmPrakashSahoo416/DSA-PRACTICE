#include<bits/stdc++.h>
using namespace std;


bool cmp(Item a, Item b){
    double f1 = (double)a.value / (double)a.weight;
    double f2 = (double)b.value / (double)b.weight;
    
    return f1 > f2;
}


double fractionalKnapsack(int W, Item arr[], int n)
{
    sort(arr, arr + n, cmp);
    int ind = 0;
    double ans = 0.00;
    while(W > 0 && ind != n){
        if(W >= arr[ind].weight){
            W -= arr[ind].weight;
            ans += (double)arr[ind].value;
            ind++;
        }else{
            ans += ((double)((double)arr[ind].value / (double)arr[ind].weight)) * (double)W;
            W = 0;
        }
    }
    return ans;
}

int main(){
	vector<int>v1 = {1,1,1};
	vector<int>v2 = {4,5,9};

	cout<<maximumActivities(v1, v2);
}