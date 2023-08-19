// leetcode 219
// Contains Duplicate II
// 给定一个整数数组和一个整数，如果该数组中存在两个数 i, j
// 满足 abs(i - j) <= 3 and nums[i] == nums[j]
// 维护一个大小为k的滑动窗口
// 如果集合中已经存在，证明找到了
// 如果集合的size大于k，证明超过了，此时我们就把最开始位置的删除即可
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  bool containsNearbyDuplicate(vector<int> &nums, int k) {
    set<int> s;

    for (int i = 0; i < nums.size(); i++) {
      // 尝试检查当前的set里面是否这个相同的值
      if (s.find(nums[i]) != s.end())
        return true;

      // 把这个值放进去
      s.insert(nums[i]);

      // 如果当前的set > k，需要删除最左边的元素
      if (s.size() > k)
        s.erase(nums[i - k]);
    }

    return false;
  }
};