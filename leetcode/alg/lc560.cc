// leetcode 560
// Subarray Sum Equals K

// 给定一个数组和一个整数k，我们想知道在这个数组中，有多少子数组的和是等于k的
// 利用前缀和+hashmap的思路能完成
// 一次遍历，一边统计前缀和，一边记录对应的前缀和的个数
// 假如s[i..j] == k
// 那么sum[j] - sum[i] = k
// 和两数之和很相似，所以我们只需要遍历并计算前缀和即可
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int subarraySum(vector<int> &nums, int k) {
    int n = nums.size();
    int sum = 0;
    unordered_map<int, int> m;
    int ans = 0;

    m[0] = 1;

    for (int i = 0; i < nums.size(); i++) {
      sum += nums[i];

      ans += m[sum - k];

      m[sum]++;
    }

    return ans;
  }
};