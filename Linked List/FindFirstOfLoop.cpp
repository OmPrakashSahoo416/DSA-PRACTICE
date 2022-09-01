#include<bits/stdc++.h>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

 ListNode *detectCycle(ListNode *head) {
        if(head == NULL)return NULL;
        ListNode* fast = head;
        ListNode* slow = head;
        bool f = false;
        
        while(fast -> next != NULL && slow != NULL){
            fast = fast -> next -> next;
            slow = slow -> next;
            
            if(fast == NULL || slow == NULL){
                return NULL;
            }
            
            if(fast == slow){
                f = true;
                break;
            }
        }
        if(!f){
            return NULL;
        }
        
        ListNode* start = head;
        while(true){
            if(start == fast){
                return start;
            }
            start = start -> next;
            fast = fast -> next;
        }
    }

int main(){
	int t;
	cin>>t;
	while(t--){
		solution();
	}
	
}