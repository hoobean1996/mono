// leetcode 312
// Burst Balloons

// 一共有n个气球，分别标号为0..n-1
// 打爆每个气球的分数分别为 nums[i-1]*nums[i]*nums[i+1]
// 如果i-1, i+1不存在，那么就令他们的值为1
// 我们想要知道最大能够得到的分数是多少

// 考虑添加两头的分数1以后，问题转换为假设打完中间的所有气球，我们能够得到的最大分数是什么
// 也可以定义dp[i][j]代表打爆[i..j]的所有气球得到的最大分数
// 答案就是dp[1][n-2]
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    
    int maxCoins(vector<int>& nums) {
        // 数组前后添加两个1来简化计算
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        
        // 定义dp[i][j]代表打掉nums[i]...nums[j]的最大值
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), 0));
        
        // nums.size() - 2是最后一个气球的位置
        // for l in last .. 1
        //  for r = l .. last
        //      for i = l .. r

        for(int l=nums.size() - 2; l>=1; l--) {
            for(int r=l; r<=nums.size()-2; r++) {
                // i = [l .. r]
                // 如果戳破第i个气球的话
                for(int i=l; i<=r; i++) {
                    // 当前的gain
                    int gain = nums[l-1] * nums[i] * nums[r+1];
                    // 剩下的两遍的最大值
                    int remain = dp[l][i-1] + dp[i+1][r];

                    dp[l][r] = max(dp[l][r], remain + gain);
                }
            }
        }
        
        return dp[1][nums.size() - 2];
    }
};