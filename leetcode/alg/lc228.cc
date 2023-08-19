// leetcode 228
// Summary Ranges
#include <string>
class Solution {
public:
  vector<string> summaryRanges(vector<int> &nums) {
    if (nums.size() == 0) {
      return {};
    }
    if (nums.size() == 1) {
      return {to_string(nums[0])};
    }
    int start = nums[0];
    int prev = nums[0];
    vector<string> ans;
    for (int i = 1; i < nums.size(); i++) {
      if (nums[i] == prev + 1) {
        prev = nums[i];
        continue;
      } else {
        if (prev == start) {
          ans.push_back(to_string(start));
        } else {
          ans.push_back(to_string(start) + "->" + to_string(prev));
        }
        start = nums[i];
        prev = nums[i];
      }
    }
    if (start == prev) {
      ans.push_back(to_string(start));
    } else {
      ans.push_back(to_string(start) + "->" + to_string(prev));
    }
    return ans;
  }
};