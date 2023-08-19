// leetcode 3
// Longest Substring without repeating characters

// 给定一个字符串，我们想知道在其中的最长不重复字串。
// 考虑维护一个滑动窗口 [l, r] 是不包含任何重复字串的区间
// 初始化的时候 l = 0, r = 0
// 当遇到一个字符c存在的时候，我们需要考虑是否这个字符的上一个位置是否在当前的滑动窗口内
// 如果是的话，我们可以移动l = m[c] + 1来修复这个区间的性质
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    int n = s.length();
    if (n == 1)
      return n;

    int l = 0;
    int r = 0;

    int ans = 0;
    map<char, int> m;

    while (r < n) {
      char c = s[r];
      // 如果c在已有的[l,r]区间，才需要更新
      if (m.count(c) && m[c] >= l) {
        l = m[c] + 1;
      }
      m[c] = r;
      // r - l + 1 就是当前的区间长度
      ans = max(ans, r - l + 1);
      r++;
    }

    return ans;
  }
};