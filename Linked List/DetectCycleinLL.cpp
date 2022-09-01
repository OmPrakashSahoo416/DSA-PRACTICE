#include<bits/stdc++.h>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycle(ListNode *head) {
    if(head == NULL)return false;
    ListNode* fast = head;
    ListNode* slow = head;
    
    while(fast -> next != NULL && slow != NULL){
        fast = fast -> next -> next;
        slow = slow -> next;
        if(fast == slow){
            return true;
        }
        if(fast == NULL || slow == NULL)return false;
    }
    return false;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		solution();
	}
	
}