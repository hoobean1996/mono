// leetcode 611
// Valid Triangle Number

// It's similar to three sum, sort + two points,
// the valid triangle number is : a + b > c
class Solution {
public:
  int triangleNumber(vector<int> &nums) {
    int n = nums.size();
    if (n < 3) {
      return 0;
    }
    int total = 0;
    sort(nums.begin(), nums.end());
    for (int i = 2; i < n; i++) {
      int l = 0;
      int r = i - 1;
      while (l < r) {
        if (nums[l] + nums[r] <= nums[i]) {
          l++;
        } else {
          total += r - l;
          r--;
        }
      }
    }

    return total;
  }
};