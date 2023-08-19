// leetcode 88
class Solution {
public:
  void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
    vector<int> ans;

    int l1 = 0;
    int l2 = 0;

    while (l1 < m && l2 < n) {
      if (nums1[l1] <= nums2[l2]) {
        ans.push_back(nums1[l1]);
        l1++;
      } else {
        ans.push_back(nums2[l2]);
        l2++;
      }
    }

    if (l1 < m) {
      for (int i = l1; i < m; i++)
        ans.push_back(nums1[i]);
    }
    if (l2 < n) {
      for (int i = l2; i < n; i++)
        ans.push_back(nums2[i]);
    }

    for (int i = 0; i < m + n; i++)
      nums1[i] = ans[i];
  }
};