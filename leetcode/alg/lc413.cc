// leetcode 413
// Arithmetic Slices
// 给定一个数组，我们想知道它的子数组中，是等差数列的子数组个数
// 定义dp[i]代表以i结尾都等差数列的个数
// dp[i] = dp[i-1] + (nums[i] - nums[i-1] == nums[i-1] - nums[i-2]) ? 1 : 0;
// 然后对整个dp数组求和即可
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return 0;

        vector<int> dp(n, 0);
        
        for(int i=2; i<n; i++) {
            if (nums[i] - nums[i-1] == nums[i-1] - nums[i-2]) dp[i] = dp[i-1] + 1;  
        }
        
        return accumulate(dp.begin(), dp.end(), 0);
    }
};