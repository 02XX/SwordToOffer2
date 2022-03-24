#include<stack>
#include<iostream>
using namespace std;
class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> S1, S2;
    MinStack() {

    }
    void push(int x) {
        S1.push(x);
        if(S2.empty())
        {
            S2.push(x);
        }
        else if(S2.top() >= S1.top())
        {
            S2.push(x);
        }
    }
    void pop() {
        if(!S1.empty())
        {
            if(!S2.empty() && S1.top() == S2.top())
            {
                S1.pop();
                S2.pop();
            }
            else
            {
                S1.pop();
            }
        }
    }
    
    int top() {
        if(!S1.empty()) 
            return S1.top();
        else
            return NULL;
    }
    
    int min() {
        if(!S2.empty()) 
            return S2.top();
        else
            return NULL;
    }
};
int main()
{
    MinStack* obj = new MinStack();
    obj->push(1);
    obj->pop();
    int param_3 = obj->top();
    int param_4 = obj->min();
    std::cout << param_3 << param_4;
    return 0;
}
/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */