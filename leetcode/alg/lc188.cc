// leetcode 188
// Best Time to Buy and Sell Stock IV

// 给定一个价格数组，如果限制我们最多进行k次交易
// 求可以达到的最大利润

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        // 令dp[i][j][0] 代表前i天已经交易过j次，当前手中无票的最大利润
        //   dp[i][j][1] 代表前i天已经交易过j次，当前手中有票的最大利润
        // i: 1 .. n
        // j: 1 .. k
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(k+1, vector<int>(2, 0)));
        // dp[0][j][0] = 0;
        // dp[i][0][0] = 0;
        
        // 非法状态
        // dp[0][j][1] = -1e6; 赋值为负无穷从而避免从这个状态转移成功
        for(int j=0; j<=k; j++) dp[0][j][1] = -1e6;
        
        // 注意到dp下标是范围是1..n, 1..k 
        // 但是prices的下标需要i-1
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=k; j++) {
                dp[i][j][0] = max(dp[i-1][j][0], dp[i-1][j][1] + prices[i-1]);
                dp[i][j][1] = max(dp[i-1][j][1], dp[i-1][j-1][0] - prices[i-1]);
            }
        }
        
        return dp[n][k][0];
    }
};