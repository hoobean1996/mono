// leetcode 20
// Valid Parentheses

// 有效的括号
// 由于括号是需要配对的，所以我们可以利用栈来进行处理
// 当遇到
// 左括号的时候，放入到栈中，遇到右括号的时候，尝试弹出栈，如果不匹配则失败
// 最终还需要考虑栈一定为空，比如 ((( 的情况

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  bool isValid(string s) {
    stack<char> sk;

    for (int i = 0; i < s.length(); i++) {
      if (s[i] == '(' || s[i] == '{' || s[i] == '[')
        sk.push(s[i]);
      else {
        if (sk.empty())
          return false;
        if (s[i] == ')' && sk.top() != '(')
          return false;
        if (s[i] == ']' && sk.top() != '[')
          return false;
        if (s[i] == '}' && sk.top() != '{')
          return false;
        sk.pop();
      }
    }

    return sk.empty();
  }
};
