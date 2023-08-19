// leetcode 150
// Eval Reverse Polish Notation

// 处理逆波兰表达式
// 遇到数字，就放入到栈中，
// 遇到符号，就从栈中弹出操作数进行计算，并将结果放入栈中。
// 唯一需要注意的是多位数字。
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int evalRPN(vector<string> &tokens) {
    stack<int> sk;

    for (int i = 0; i < tokens.size(); i++) {
      int len = tokens[i].length();
      int firstChar = tokens[i][0];
      // 确保只是符号
      if ((firstChar == '+' && len == 1) || (firstChar == '-' && len == 1) ||
          (firstChar == '*' && len == 1) || (firstChar == '/' && len == 1)) {
        if (firstChar == '+') {
          int u = sk.top();
          sk.pop();
          int v = sk.top();
          sk.pop();
          sk.push(v + u);
        } else if (firstChar == '-') {
          int u = sk.top();
          sk.pop();
          int v = sk.top();
          sk.pop();
          sk.push(v - u);
        } else if (firstChar == '*') {
          int u = sk.top();
          sk.pop();
          int v = sk.top();
          sk.pop();
          sk.push(v * u);
        } else if (firstChar == '/') {
          int u = sk.top();
          sk.pop();
          int v = sk.top();
          sk.pop();
          sk.push(v / u);
        }

      } else {
        // 数字的情况
        int n = 0;
        int sign = 1;
        for (int j = 0; j < len; j++) {
          if (tokens[i][j] == '-') {
            sign = -1;
            continue;
          }
          n = n * 10 + (tokens[i][j] - '0');
        }
        sk.push(n * sign);
      }
    }

    return sk.top();
  }
};