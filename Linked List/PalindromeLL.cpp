#include<bits/stdc++.h>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

 bool isPalindrome(ListNode* head) {
    if(head == NULL || head -> next == NULL){
        return true;
    }
    ListNode* slow = head;
    ListNode* fast = head;
    
    while(fast -> next != NULL && fast -> next -> next != NULL){
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    ListNode* rev = slow -> next;
    ListNode* prev = NULL;
    while(rev != NULL){
        ListNode* fr = rev -> next;
        rev -> next = prev;
        prev = rev;
        rev = fr;
    }
    slow -> next = prev;
    slow  = slow -> next;
    bool ans = true;
    ListNode* frst = head;
    while(slow != NULL){
        if(slow -> val != frst -> val){
            return false;
        }
        slow = slow -> next;
        frst = frst -> next;
    }    
    return ans;                            
}

int main(){
	int t;
	cin>>t;
	while(t--){
		solution();
	}
	
}