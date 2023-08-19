// leetcode 350
// Intersection of Two Arrays II

// 相比直接求交集
// 我们可以利用unordered_map来计数
// 每找到一个就减一

class Solution {
public:
  vector<int> intersect(vector<int> &nums1, vector<int> &nums2) {
    unordered_map<int, int> m1;
    unordered_map<int, int> m2;

    for (const int &x : nums1)
      m1[x]++;
    for (const int &x : nums2)
      m2[x]++;
    vector<int> ans;

    for (int i = 0; i < nums2.size(); i++) {
      int val = nums2[i];
      // 如果该元素出现在两个集合中，较小的次数就是结果
      int count = min(m1[val], m2[val]);
      for (int i = 0; i < count; i++) {
        ans.push_back(val);
        m1[val]--;
        m2[val]--;
      }
    }

    return ans;
  }
};