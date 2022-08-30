#include<bits/stdc++.h>
using namespace std;


struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* reverseList(ListNode* head) {
    ListNode* curr = head;
    ListNode* prev = NULL;
    while(curr != NULL){
        ListNode* frwd = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = frwd;
    }
    return prev;
}

int main(){
	int n;
	cin>>n;
	ListNode* head = new ListNode(-1);
	ListNode* t2 = head;
	for(int i = 0; i < n; i++){
		int x;
		cin>>x;
		ListNode* temp = new ListNode(x);
		head -> next = temp;
		head = head -> next;
	}
	ListNode* ans = new ListNode(-1);
	head = t2;
	ans -> next = reverseList(head);
	ans = ans -> next;
	while(ans -> next != NULL){
		cout<<ans -> val<<" ";
		ans = ans -> next;
	}
	
}