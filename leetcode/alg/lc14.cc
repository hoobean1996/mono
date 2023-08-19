// leetcode 14
// Longest Common Prefix

// 给定一组字符串，我们想找到所有字符串的公共前缀
// 利用公共前缀的长度最多不超过最短的字符串
// 就可以得到二分的区间，然后就二分前缀即可
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  bool isCP(vector<string> &strs, int len) {
    string prefix = strs[0].substr(0, len);
    for (int i = 1; i < strs.size(); i++) {
      if (strs[i].substr(0, len) != prefix)
        return false;
    }
    return true;
  }

  string longestCommonPrefix(vector<string> &strs) {
    if (strs.size() == 0)
      return "";

    int minL = 1e9;
    for (const string s : strs)
      minL = minL < s.length() ? minL : s.length();

    int l = 1;
    int r = minL;

    while (l <= r) {
      int mid = l + (r - l) / 2;
      if (isCP(strs, mid))
        l = mid + 1;
      else
        r = mid - 1;
    }

    return strs[0].substr(0, (l + r) / 2);
  }
};