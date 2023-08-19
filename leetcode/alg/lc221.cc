// leetcode 221
// Maximal Square

// 给定一个m x n的矩阵，其中包含0和1，找到在这个矩阵中最大的正方形
// 在这个正方形中全部都是1

// 考虑 [i, j]为右下角的最大正方形
// 因为要求是正方形
// 所以递推的状态里面 dp[i-1][j] dp[i][j-1] dp[i-1][j-1] 分别代表三个子状态
// dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1
// 因为要形成正方形，所以一定会受最小的那个影响
#include <bits/stdc++.h>
class Solution {
public:
  int maximalSquare(vector<vector<char>> &matrix) {
    // 定义 dp[i][j] 为以i，j为右下角的最大正方形的边长
    if (matrix.empty() || matrix[0].empty())
      return 0;

    int m = matrix.size();
    int n = matrix[0].size();

    int mx = 0;

    vector<vector<int>> dp(m, vector<int>(n, 0));

    // dp[i][j] 定义为以(i, j)作为正方形右下角的最大边长
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        // 第一行 第一列处理
        if (i == 0 || j == 0) {
          dp[i][j] = matrix[i][j] == '1';
        } else {
          // 其他情况依赖于这个值=1
          if (matrix[i][j] == '1') {
            dp[i][j] =
                min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
          } else {
            dp[i][j] = 0;
          }
        }
        mx = max(mx, dp[i][j]);
      }
    }
    return mx * mx;
  }
};