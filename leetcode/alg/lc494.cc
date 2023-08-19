// leetcode 494
// Target Sum

// 给定一个数组，和一个目标值target
// 我们需要在数组中的每个元素都添加 + | -
// 然后连接起来的值应该等于target
// 问有多少种拼接方法

// 假设两个集合 left - right = S 假设right > 0
// left + right = sum
// left = (s + sum) / 2
// 所以这道题本质上是考察在nums中和为left的组合

#include <bits/stdc++.h>

using namespace std;

// 递归搜索
class Solution {
public:
    int ans = 0;
    void dfs(int index, vector<int>& nums, int path, int target) {
        if (index == nums.size()){
            if (path == target) ans++;
            return;
        }

        // 选择该元素
        if (nums[index] <= target) dfs(index + 1, nums, path + nums[index], target);
        // 不选择该元素
        dfs(index+1, nums, path, target);
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        
        int left = (sum + target) / 2;
        
        if (target > sum || (target + sum) % 2 == 1) return 0;
        
        dfs(0, nums, 0, left);
        
        return ans;
    }
};



class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(), nums.end(), 0);

        if (target > sum || (target + sum) % 2 == 1) return 0;

        target =  target + (sum - target) / 2;
        int n = nums.size();
        
        if (target < 0) return 0;
        
        vector<int> dp(target+1, 0);
        // 定义dp[i]是拼成i有dp[i]种拼法
        // dp[0] = 1
        // 对于任意的dp[j] 对于比他小的那些数 dp[j] += dp[j-nums[i]]
        dp[0] = 1;
        for(int i=0; i<n; i++) {
            for(int j=target; j >= nums[i]; j--) dp[j] += dp[j-nums[i]];
        }    
        return dp[target];
    }
};