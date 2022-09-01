#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};

Node* mergeSortedLists(Node* l1, Node* l2){
    if(l1 == NULL)return l2;
    
    if(l2 == NULL)return l1;
    
    if(l2 -> data < l1 -> data){
        swap(l2, l1);
    }
    Node* root = l1;
    while(l1 != NULL && l2 != NULL){
        Node* t = NULL;
        while(l1 != NULL && (l1 -> data <= l2 -> data)){
            t = l1;
            l1 = l1 -> bottom;
        }
        t -> bottom = l2;
        swap(l2, l1);
    }
    return root;
}

Node *flatten(Node *root)
{
    if(root == NULL || root -> next == NULL)return root;
    root -> next = flatten(root -> next);
    
    root = mergeSortedLists(root,root -> next);
    return root;
    
}

int main(){
	int t;
	cin>>t;
	while(t--){
		solution();
	}
	
}