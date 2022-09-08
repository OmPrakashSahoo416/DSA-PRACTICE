#include<bits/stdc++.h>
using namespace std;

// void solution(){
// }
class Queue {
    int* arr;
    int fron;
    int back;
    int size;
public:
    Queue() {
        arr = new int[5000];
        fron = 0;
        back = 0;
        size = 0;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        if(size == 0){
            return true;
        }
        return false;
    }

    void enqueue(int data) {
        size++;
        arr[back++] = data;
    }

    int dequeue(){
        size--;
        if(size < 0){
            size = 0;
            return -1;
        }
        int res = arr[fron++];
        return res;
    }

    int front() {
        if(size == 0){
            return -1;
        }
        int res = arr[fron];
        return res;
    }
};

int main(){
	// int t;
	// cin>>t;
	// while(t--){
	// 	solution();
	// }
}