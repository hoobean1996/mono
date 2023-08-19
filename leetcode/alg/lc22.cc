// leetcode 22
// Generate Parentheses

// 生成合法的括号
// 由于括号是需要配对的，一种方法不考虑配对，然后无脑的放符号，最后检查是否合法
// 但是这样搜索空间太大
// 所以我们维护当前放入的左括号和右括号的数量
// 终止的情况是左括号和右括号配对，并且等于给定的长度

// 这个思路很关键，关于括号的搜索需要考虑左右配对

// l 代表left
// r 代表right

// The total time complexity O(4^n / sqrt(n))
// The total space complexity O(4^n / sqrt(n))
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  void dfs(int l, int r, string tmp, vector<string> &ans, int n) {
    if (l == n && l == r) {
      ans.push_back(tmp);
      return;
    }

    if (l < n)
      dfs(l + 1, r, tmp + "(", ans, n);

    if (r < min(l, n))
      dfs(l, r + 1, tmp + ")", ans, n);
  }

  vector<string> generateParenthesis(int n) {
    vector<string> ans;
    dfs(0, 0, "", ans, n);
    return ans;
  }
};