// leetcode 75
// Sort Colors

#include <bits/stdc++.h>

using namespace std;

// 颜色排序
class Solution {
public:
  void sortColors(vector<int> &nums) {
    // p0 是指向0
    // p2 是指向2
    int cur = 0;
    int p0 = 0;
    int p2 = nums.size() - 1;

    // 遇到1 直接继续
    // 遇到0的话 就和p0交换位置
    // 遇到2的话 就和p2交换位置
    while (cur <= p2) {
      if (nums[cur] == 0)
        swap(nums[cur++], nums[p0++]);
      else if (nums[cur] == 2)
        swap(nums[cur], nums[p2--]);
      else
        cur++;
    }
  }
};