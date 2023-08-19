// leetcode 213
// House Robber II

// 打家劫舍
// 你是一个专业的小偷，计划沿街的房屋。每件房内有一定的现金，如果连续偷窃两个相邻
// 的房屋的话，就会被发现。
// 问能够偷窃到的最大金额是多少?
// 这次的房屋是环形的
// 如果我们在头尾的两个房屋中选择任何一个，就能把问题转换为最简单的形式
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int robHelper(vector<int>& nums) {
        vector<int> dp(nums.size() + 1, 0);
        
        
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) return nums[0] > nums[1] ? nums[0] : nums[1];
        
        dp[1] = nums[0];
        
        for(int i=2; i<=nums.size(); i++) {
            dp[i] = max(dp[i-1], dp[i-2] + nums[i-1]);
        }
        
        return dp[nums.size()];
    }
    
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        
        vector<int> s1 = nums;
        s1.erase(s1.begin());
        
        vector<int> s2 = nums;
        s2.pop_back();
        
        return max(robHelper(s1), robHelper(s2));
    }
};