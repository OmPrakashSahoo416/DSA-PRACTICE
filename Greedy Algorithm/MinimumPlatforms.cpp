#include<bits/stdc++.h>
using namespace std;

int findPlatform(int arr[], int dep[], int n)
{
    int ans = 1;
	sort(arr, arr + n);
	sort(dep, dep + n);
	int platform = 1;
	int i1 = 1, i2 = 0;
	while(i1 < n && i2 < n){
	    if(arr[i1] <= dep[i2]){
	        platform++;
	        i1++;
	    }
	    else{
	        platform--;
	        i2++;
	    }
	    
	    ans = max(ans, platform);
	}
	return ans;
}

int main(){
	
}