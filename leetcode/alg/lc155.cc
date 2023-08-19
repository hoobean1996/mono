// leetcode 155
// Min Stack

// 实现一个最小栈
#include <bits/stdc++.h>

using namespace std;

class MinStack {
private:
  // 一个用来存数值
  vector<int> s;
  // 一个用来存最小值
  vector<int> mi;

public:
  MinStack() {
    s = vector<int>();
    mi = vector<int>();
  }

  void push(int val) {
    s.push_back(val);
    if (mi.size() == 0) {
      mi.push_back(val);
    } else {
      int top = mi.back();
      if (val < top)
        mi.push_back(val);
      else
        mi.push_back(top);
    }
  }

  void pop() {
    s.pop_back();
    mi.pop_back();
  }

  int top() { return s.back(); }

  int getMin() { return mi.back(); }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */