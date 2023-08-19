// leetcode 1262
// Greatest Sum Divisible by Three

// 3,6,5,1,8
// 18
// 3,6,1,8

// 定义dp[i]是前i个数的能被三整除的和
// 定义dp[0] 代表%3 == 0的最大和
// 定义dp[1] 代表%3 == 1的最大和
// 定义dp[2] 代表%3 == 2的最大和
class Solution {
public:
  int maxSumDivThree(vector<int> &nums) {
    vector<int> dp(3, INT_MIN);
    dp[0] = 0;
    for (int num : nums) {
      vector<int> temp(3, 0);
      for (int i = 0; i < 3; i++) {
        // i + num % 3
        // 如果我们把num 加入到i中
        // 那么原来的余数i 可能会变
        temp[(i + num) % 3] = max(dp[(i + num) % 3], dp[i] + num);
      }
      dp = temp;
    }
    return dp[0];
  }
};