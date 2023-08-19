// leetcode 322
// Coin Change

// 零钱兑换
// 给定一组硬币，我们想知道为了凑出给定的钱数最少需要的硬币是多少.
// 比如 [1,2,5], target=11, 答案是3: 5 + 5 + 1
#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) return 0;
        
        int _max = amount + 1;
        // 定义dp[i]是价值为i的时候最小个数
        // 初始化: dp[0] = 0
        // 转移方程: dp[i] = max(dp[i], dp[i - coins[j]] + 1)
        // 考虑到价值为i的时候，我们可以用小的coins拼起来，所以内层循环遍历所有可能的拼法
        vector<int> dp(_max, _max);
        dp[0] = 0;
        for(int i=1; i<=amount; i++) {

            for(int j=0; j<coins.size(); j++) {
                // 拿出一个较小的硬币的情况
                if (coins[j] <= i) {
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }
        
        return dp[amount] > amount ? -1 : dp[amount];
    }
};