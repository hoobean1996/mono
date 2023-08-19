// leetcode 279
// Perfect Squares 
// 返回一个数的平方数之和

// 这道题用数学公式太不熟悉
// 还是用DP好一些
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numSquares(int n) {
        // 定义dp[i]为i所需要的个数
        // 注意初始化为无穷大
        vector<int> dp(n + 1, INT_MAX - 1);

        // 只有0是合法的
        // 如果不是平方数，那么就是不合法的，需要注意
        dp[0] = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j * j <= i; j++) {
                // 当前数的方案数 与比他小的平方数之间的关系
                dp[i] = min(dp[i], dp[i - j * j] + 1);
            }
        }

        return dp[n];
    }
};
