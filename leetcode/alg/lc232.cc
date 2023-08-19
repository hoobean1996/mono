// leetcode 232
// Implementing Queue using Stacks

class MyQueue {
public:
    stack<int> s1;
    stack<int> s2;
    
    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        if (!s2.empty()) {
            int val = s2.top();
            s2.pop();
            return val;
        }
        
        while(s1.size()) {
            s2.push(s1.top()); s1.pop();
        }
        int val = s2.top(); s2.pop();
        return val;
    }
    
    int peek() {
        if (!s2.empty()) return s2.top();
        while(s1.size()) {
            s2.push(s1.top()); s1.pop();
        }
        return s2.top();
    }
    
    bool empty() {
        return s1.size() + s2.size() == 0;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */