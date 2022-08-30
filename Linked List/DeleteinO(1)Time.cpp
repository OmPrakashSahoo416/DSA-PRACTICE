#include<bits/stdc++.h>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void deleteNode(ListNode* node) {
        node -> val = node -> next -> val;
        node -> next = node -> next -> next;
}

int main(){
	int n;
	cin>>n;
	int k;
	cin>>k;
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
	ans -> next = removeNthFromEnd(head, k);
	ans = ans -> next;
	while(ans != NULL){
		cout<<ans -> val<<" ";
		ans = ans -> next;
	}
	
}