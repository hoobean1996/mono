// leetcode 316

// RemoveDuplicateLetters
// 给定一个字符串，我们想要删除其中重复的字符，同时留下的字符串是字典序最小的。

// 删除重复的字符，但是要保证最终的结果是最小的字典序
// 用一个map来快速判断一个字符是否重复，我们也需要记录一个字符的最后出现的下标
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  string removeDuplicateLetters(string s) {
    stack<char> sk;

    // 确保只有一个字符
    unordered_map<char, bool> seen;

    // 用于快速判断后面还有某个字符吗
    unordered_map<char, int> last_occurence;

    for (int i = 0; i < s.length(); i++)
      last_occurence[s[i]] = i;

    for (int i = 0; i < s.length(); i++) {
      char c = s[i];
      // 如果没有看到该字符
      // A D _c
      // 如果当前的字符比上一个字符大，同时D还有更多的，那么我们可以删除前一个字符
      // 维护的是字典序尽可能（如果没有没有更多的字符了不能弹出)单调递减的栈
      if (seen.count(c) == 0) {
        // 可以删除这个栈顶字符的条件是
        // 1. 栈顶字符比当前字符大
        // 2. 栈顶字符在后面还会出现
        while (!sk.empty() && c < sk.top() && last_occurence[sk.top()] > i) {
          seen.erase(sk.top());
          sk.pop();
        }
        seen[c] = true;
        sk.push(c);
      }
    }

    string ans;
    while (!sk.empty()) {
      ans += sk.top();
      sk.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
  }
};