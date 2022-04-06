#include<stack>
#include<iostream>
using namespace std;
class CQueue {
public:
    stack<int>* tail;
    stack<int>* head;
    CQueue() {
        tail = new stack<int>();
        head = new stack<int>();
    }
    void appendTail(int value) {
        while(!head->empty())
        {
            tail->push(head->top());
            head->pop();
        }
        tail->push(value);
    }
    int deleteHead() {
        while(!tail->empty())
        {
            head->push(tail->top());
            tail->pop();
        }
        if(!head->empty())
        {
            int r = head->top();
            head->pop();
            return r;
        }
        else
            return -1;
    }
};
/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */