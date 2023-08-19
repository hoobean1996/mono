// leetcode 122
// Best Time to Buy and Sell Stock II

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        // 记 dp[i][0] 是第i天无票的时候最大利润
        // 记 dp[i][1] 是第i天有票的时候最大利润
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        dp[0][0] = 0;
        dp[0][1] = -1e6;

        for (int i = 1; i <= n; i++)
        {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i - 1]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i - 1]);
        }

        return dp[n][0];
    }
};