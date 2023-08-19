// leetcode 33
// Search in Rotated Sorted Array
// 旋转数组搜索
// O(n)的方法是最简单的
class Solution {
public:
  // Need to analysis the rotated sorted array's property
  int search(vector<int> &nums, int target) {
    int l = 0;
    int r = nums.size() - 1;
    if (l == r)
      return nums[0] == target ? 0 : -1; // 处理一个元素的情况

    // [0, n-1]
    // 闭区间模板
    while (l <= r) {
      int mid = l + (r - l) / 2;

      if (target == nums[mid])
        return mid;
      // 由于是旋转过后的
      // 1234567
      // 4567 123
      // 首先利用mid和左右端点的关系
      // 确定当前是处理第一段 还是第二段
      if (nums[l] <= nums[mid]) {
        if (target >= nums[l] && target <= nums[mid])
          r = mid;
        else
          l = mid + 1;
      } else {
        if (target >= nums[mid] && target <= nums[r])
          l = mid;
        else
          r = mid - 1;
      }
    }

    return -1;
  }
};