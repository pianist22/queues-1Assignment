#include<iostream>
#include<vector>

using namespace std;

class MyCircularDeque {
public:
    int f;
    int b;
    int s; //curr  size
    int c; //capacity
    vector<int> arr;
    MyCircularDeque(int k) {
        f = -1;
        b = -1;
        s = 0;
        c = k;
        vector<int> v(k);
        arr = v;
    }
    
    bool insertFront(int val) { //push_front
        if(isFull()) return false;
        else if(f==-1 && b==-1) {
            f = b = 0;
            arr[f]=val;
        }
        else if(f==0) {
            f = c-1;
            arr[f] = val;
        }
        else{
            f = f-1;
            arr[f] = val;
        }
        s++;
        return true;
    }
    
    bool insertLast(int val) { //push_back
        if(isFull()) return false;
        else if(f==-1 && b==-1) {
            f = b =0;
            arr[b] = val;
        }
        else if(b == c-1) {
            b =0;
            arr[b] = val;
        }
        else {
            b = b+1;
            arr[b] = val;
        }
        s++;
        return true;
    }
    
    bool deleteFront() {
        if(isEmpty()) return false;
        else if(f == c-1) f =0;
        else f++;
        s--;
        return true;
    }
    
    bool deleteLast() {
        if(isEmpty()) return false;
        else if(b == 0) b = c-1;
        else b = b-1; 
        s--;
        return true;
    }
    
    int getFront() {
        if(isEmpty()) return -1;
        return arr[f];
    }
    
    int getRear() {
        if(isEmpty()) return -1;
        return arr[b];
    }
    
    bool isEmpty() {
        if(s == 0) return true;
        else return false;
    }
    
    bool isFull() {
        if(s==c) return true;
        else return false;
    }
};
