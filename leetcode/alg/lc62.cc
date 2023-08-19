// leetcode 62 
// Unique Path

#include <bits/stdc++.h>

using namespace std;

// 求解到达某个位置的方法
class Solution {
public:
    int uniquePaths(int m, int n) {
        // 定义dp[i][j]是到达(i,j)需要的步数
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        
        for(int i=0; i<m; i++) dp[i][0] = 1;
        for(int j=0; j<n; j++) dp[0][j] = 1;
        
        // 对于每个(i,j)它可以来自 (i-1, j) + (i, j-1)
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        
        return dp[m-1][n-1];
    }
};

