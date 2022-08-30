#include<bits/stdc++.h>
using namespace std;


struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* middleNode(ListNode* head) {
	ListNode* temp = head;
    int len = -1;
    while(temp != NULL){
    	len++;
    	temp = temp -> next;
    }
    cout<<len<<" ";
    int mid = (len / 2) + 1;
    int ct = 0;
    while(ct < mid){
    	head = head -> next;
    	ct++;
    }
    return head;
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
	ans -> next = middleNode(head);
	ans = ans -> next;
	while(ans != NULL){
		cout<<ans -> val<<" ";
		ans = ans -> next;
	}
	
}