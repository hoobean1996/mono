// leetcode 153
// Find Minimum in Rotated Sorted Array
// 给定一个有序数组
// rotate一次以后，我们希望找到其最小值
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int findMin(vector<int> &nums) {
    int l = 0;
    int r = nums.size() - 1;
    while (l < r) {
      int mid = l + (r - l) / 2;

      if (nums[mid] < nums[r])
        r = mid;
      else
        l = mid + 1;
    }
    return nums[l];
  }
};