// leetcode 714
// Best Time to Buy and Sell with Transaction Fee

// 每笔交易是有交易费的，没有交易数目限制
// 考虑dp[i][0|1] 代表第几天的利润
// 如果是 0 的话，就是没有票的时候
// 如果是 1 的话，就是有票的时候
#include <bits/stdc++.h>

using namespace std;

int maxProfit(vector<int>& prices, int fee) {
    int n = prices.size();
    vector<vector<int>> dp(n+1, vector<int>(2, 0));

    // 初始化的时候，dp[0][1]是无效的状态
    dp[0][0] = 0;
    dp[0][1] = -1e6;
    
    // 和多次交易的题一样，唯一的区别就是加上固定的fee
    for(int i=1; i<=n; i++) {
        // 考虑状态转移
        // 第i天没有票的话，可以是从i-1天没有票的情况转移过来，也可以是i-1天有票，然后卖掉转移过来
        dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i-1] - fee);
        // 第i天有票的话，可以是从i-1天有票转移的情况过来，也可以是i-1天没有票，但是买了一个票转移过来
        dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i-1]);
    }

    return dp[n][0];
}