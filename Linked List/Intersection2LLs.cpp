#include<bits/stdc++.h>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* l1 = headA;
        ListNode* l2 = headB;
        
        while(l1 != l2){
            l1 = l1 -> next;
            l2 = l2 -> next;
            if(!l1 && !l2){
                return NULL;
            }
            
            if(l1 == NULL){
                l1 = headB;
            }
            if(l2 == NULL){
                l2 = headA;
            }
        }
        
        return l1;
    }

int main(){
	int t;
	cin>>t;
	while(t--){
		solution();
	}
	
}