// leetcode 128
// Longest Consecutive Sequence
#include <bits/stdc++.h>

using namespace std;

// 给定一个没有排序过的数组
// 求这个数组中的最大连续的长度
class Solution {
public:
  int longestConsecutive(vector<int> &nums) {
    // 利用整个数组构造一个集合
    set<int> s = set<int>(nums.begin(), nums.end());

    int ans = 0;

    // 遍历整个集合
    for (const int n : nums) {
      // 如果当前值的前驱不存在
      // 这个意味着我们每次都用一段区间的最小值作为起点
      if (s.find(n - 1) == s.end()) {
        int cur = n;
        int curAns = 1;

        // 一直寻找 直到不满足条件
        while (s.find(cur + 1) != s.end()) {
          cur++;
          curAns++;
        }

        ans = max(ans, curAns);
      }
    }

    return ans;
  }
};