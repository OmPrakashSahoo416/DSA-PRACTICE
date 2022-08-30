#include<bits/stdc++.h>
using namespace std;


struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    if(list1 == NULL)return list2;
    if(list2 == NULL)return list1;

    ListNode* ll1 = list1;
    ListNode* ll2 = list2;
    if(ll1 -> val > ll2 -> val){
    	swap(ll1, ll2);
    }
    ListNode* res = ll1;
    while(ll1 != NULL && ll2 != NULL){
    	ListNode* t;

    	while(ll1 != NULL && ll1 -> val <= ll2 -> val){
    		t = ll1;
    		ll1 = ll1 -> next;
    	}
    	t -> next = ll2;
    	swap(ll1, ll2);
    }
    return res;
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
	ans -> next = mergeTwoLists(head, head);
	ans = ans -> next;
	while(ans != NULL){
		cout<<ans -> val<<" ";
		ans = ans -> next;
	}
	
}