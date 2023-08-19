// leetcode 581
// Shortest Unsorted Continous Subarray

class Solution {
public:
  int findUnsortedSubarray(vector<int> &nums) {
    auto copy = nums;

    sort(nums.begin(), nums.end());
    int l = 0;
    for (; l < nums.size(); l++) {
      if (nums[l] != copy[l])
        break;
    }
    int r = nums.size() - 1;
    for (; r >= l; r--) {
      if (nums[r] != copy[r])
        break;
    }
    return r - l + 1;
  }
};