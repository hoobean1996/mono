// leetcode 42
// Find All Duplication in an Array
// 由于所有的元素都在 [1..n]之间
// 那么可以把他们放到 0..n-1之间
//
class Solution {
public:
  vector<int> findDuplicates(vector<int> &nums) {
    vector<int> res;
    for (int i = 0; i < nums.size(); ++i) {
      int idx = abs(nums[i]) - 1;
      if (nums[idx] < 0)
        res.push_back(idx + 1);
      nums[idx] = -nums[idx];
    }
    return res;
  }
};