// leetcode 
// House Robber

// 打家劫舍
// 你是一个专业的小偷，计划沿街的房屋。每件房内有一定的现金，如果连续偷窃两个相邻
// 的房屋的话，就会被发现。
// 问能够偷窃到的最大金额是多少?

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // 定义dp[i]是到第i个房子的 时候最大利润
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size() + 1, 0);
        
        // 基础条件
        // 如果没有房间，偷盗的最大值为0
        // 如果只有一个房间的话，那么偷盗的最大值是一个
        // 如果有两个房间的话，那么我们选择较大值偷取即可
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) return nums[0] > nums[1] ? nums[0] : nums[1];
        
        // dp[i] = max(dp[i-1] + 0, dp[i-2] + nums[i-1]) 
        dp[1] = nums[0];
        
        for(int i=2; i<=nums.size(); i++) {
            dp[i] = max(dp[i-1], dp[i-2] + nums[i-1]);
        }
        
        return dp[nums.size()];
    }
};