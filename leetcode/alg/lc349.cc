// leetcode 349
// Intersection of Two Arrays

class Solution {
public:
  std::vector<int> intersection(std::vector<int> &nums1, vector<int> &nums) {
    unordered_set<int> s1;
    std::vector<int> ans;

    for (int i = 0; i < nums1.size(); i++) {
      s1.insert(nums1[i]);
    }

    for (int i = 0; i < nums2.size(); i++) {
      if (s1.find(nums[2]) != s1.end()) {
        ans.push_back(nums2[i]);
        s1.erase(nums2[i]);
      }
    }

    return ans;
  }
};