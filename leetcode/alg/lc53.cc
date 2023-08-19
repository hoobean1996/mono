// leetcode 53
// Maximum Subarray

// 给定一个数组，我们想知道其中的最大和的子数组的是多少
// 可以定义dp[j]是以j为结尾的最大值
// 那么我们可以知道 dp[j] 要不就是和前面的子数组连续起来
// 要么就是新的一个子数组的开始
// sum = max(nums[i], sum + nums[i]) -> 两种情况的最大值
// dp[i] = max(dp[i] + nums[i], nums[i])
// 但是由于我们只需要知道最大值，所以用sum表示是当前连续的子数组的和
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maxSubArray(vector<int> &nums) {
    if (nums.size() == 0)
      return 0;

    int sum = 0;
    int max_sum = nums[0];

    for (int i = 0; i < nums.size(); i++) {
      sum = max(nums[i], sum + nums[i]);
      max_sum = max(max_sum, sum);
    }

    return max_sum;
  }
};