// leetcode 416
// Partition Equal Subset Sum

// 考虑一个集合，我们想知道能否将这个集合划分为两个子集
// 同时两个子集的和相同
// 1. 如果存在一个数超过了整个集合的一半 那么肯定是分不了的
// 2. 如果整个集合的和是奇数，那么肯定也是分不了的
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        int maxElement = *max_element(nums.begin(), nums.end());

        // 如果是奇数，肯定是false
        if (totalSum % 2 != 0) return false;
        // 如果最大元素比所有元素和的一半还大，肯定是false
        if (maxElement > totalSum / 2) return false;

        int subSum = totalSum / 2;
        int n = nums.size();
        
        // 定义dp[i][sum]代表如果和sum能否用0..i的数组表示
        // 初始化: dp[0][0] = true
        // 转移方程: 
        //  考虑dp[i-1][j]如果能为true，意味着不需要第当前元素就能构成
        //  考虑dp[i-1][j]不为true，那么我们需要就考虑dp[i-1][j-nums[i]]是否true
        vector<vector<int>> dp(n+1, vector<int>(subSum+1, 0));
        dp[0][0] = true;
        
        for(int i=1; i<=n; i++) {
            int cur = nums[i-1];
            for(int j=0; j<=subSum; j++) {
                if (j < cur) dp[i][j] = dp[i-1][j];
                else dp[i][j] = dp[i-1][j] || dp[i-1][j-cur];
            }
        }
        
        return dp[n][subSum];
    }
};