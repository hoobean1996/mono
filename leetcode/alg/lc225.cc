// leetcode 225
// Implementing Stack using Queues

#include <bits/stdc++.h>

using namespace std;

class MyStack {
public:
    queue<int> q1;
    queue<int> q2;
    int _top;
    
    MyStack() {}
    
    void push(int x) {
        q1.push(x);
        _top = x;
    }
    
    int pop() {
        while(q1.size() > 1) {
            q2.push(q1.front()); q1.pop();
        }
        
        int popup = q1.front();
        q1.pop();
        
        while(q2.size() > 0) {
            _top = q2.front();
            q1.push(q2.front()); q2.pop();
        }
        
        return popup;
    }
    
    int top() {
        return _top;
    }
    
    bool empty() {
        return q1.size() + q2.size() == 0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */