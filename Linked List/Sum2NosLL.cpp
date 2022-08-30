#include<bits/stdc++.h>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* c1 = l1;
    ListNode* c2 = l2;
    ListNode* ans = new ListNode(10);
    ListNode* a2 = ans;
    int carry = 0;
    while(c1 != NULL || c2 != NULL || carry){
        int sum = 0;
        if(c1 != NULL){
            sum += c1 -> val;
            c1 = c1 -> next;
        }
        if(c2 != NULL){
            sum += c2 -> val;
            c2 = c2 -> next;
        }
        
        sum += carry;
        carry = sum / 10;
        ListNode* num = new ListNode(sum % 10);
        a2 -> next = num;
        a2 = a2 -> next;
    }
    return ans -> next;
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
	ans -> next = addTwoNumbers(head, head);
	ans = ans -> next -> next;
	while(ans != NULL){
		cout<<ans -> val<<" ";
		ans = ans -> next;
	}
	
}