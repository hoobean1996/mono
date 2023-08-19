// leetcode 136
// Single Number
class Solution {
public:
  int singleNumber(vector<int> &nums) {
    if (nums.size() == 1)
      return nums[0];

    int x = nums[0];
    for (int i = 1; i < nums.size(); i++)
      x ^= nums[i];
    return x;
  }
};