// leetcode 217
// Contains Duplicate

// 1. 使用hashmap 时间复杂度为O(n) 空间复杂度为O(n)
// 2. 使用sort 时间复杂度为O(nlogn) 空间复杂度为O(1)
class Solution {
public:
  bool containsDuplicate(std::vector<int> &nums) {
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size() - 1; i++) {
      if (nums[i + 1] == nums[i])
        return true;
    }
    return false;
  }
};
