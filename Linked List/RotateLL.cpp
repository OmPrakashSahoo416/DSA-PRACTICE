#include<bits/stdc++.h>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL)return head;
        // k % len front back
        int len = 0;
        ListNode* t = head;
        while(t){
            t = t -> next;
            len++;
        }
        int num = k % len;
        if(num == 0)return head;
        t = head;
        //len - num + 1 from first
        int from1st = len - num + 1;
        int ind = 0;
        ListNode* anshead = NULL;
        while(ind != from1st){
            ind++;
            anshead = t;
            t = t -> next;
        }
        ListNode* ans = anshead;
        while(anshead -> next != NULL){
            anshead = anshead -> next;
        }
        t = head;
        ind = 0;
        while(ind != from1st - 1){
            anshead -> next = new ListNode(t -> val);
            ind++;
            anshead = anshead -> next;
            t = t -> next;
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