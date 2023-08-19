// leetcode 34
// Find First and Last Position of Element in Sorted Array

class Solution {
public:
  int findBound(vector<int> &nums, int target, bool isFirst) {
    int n = nums.size();
    int l = 0;
    int r = n - 1;

    while (l <= r) {
      int mid = l + (r - l) / 2;

      // 通过二分法找上下区间
      // 只需要在 == target里面加入条件
      // 由于我们需要确定是上区间还是下区间，所以实际上条件变成了
      // nums[mid] == target
      //  -> mid == l (最左边) || nums[mid-1] != target
      //  非最左边，但是左边的元素不同，不能移动
      if (nums[mid] == target) {
        if (isFirst) {
          // mid 是最左侧的元素
          // nums[mid-1] 不为target
          if (mid == l || nums[mid - 1] != target)
            return mid;
          r = mid - 1;
        } else {
          if (mid == r || nums[mid + 1] != target)
            return mid;
          l = mid + 1;
        }
      } else if (nums[mid] > target)
        r = mid - 1;
      else
        l = mid + 1;
    }

    return -1;
  }

  vector<int> searchRange(vector<int> &nums, int target) {
    int f = findBound(nums, target, true);
    if (f == -1)
      return {-1, -1};
    int s = findBound(nums, target, false);
    return {f, s};
  }
};