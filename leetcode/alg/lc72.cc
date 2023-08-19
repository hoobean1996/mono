// leetcode 72
// Edit Distance

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int minDistance(string word1, string word2) {
    // 设dp[i][j]表示word1前i个字符和word2前j个字符的编辑距离
    // case 1: word1[i] == word2[j] => dp[i][j] = dp[i-1][j-1];
    // case 2: word1[i] != word2[j]
    //  - update: update a[i] as b[i] -> dp[i][j] = dp[i-1][j-1]
    //  - insert: insert b[i] after a[i] -> dp[i][j] = dp[i][j-1] +1
    //  已经把a的前i-1个字符改造成b的前j个字符，所以
    //  - delete: delete a[i] -> dp[i][j] = dp[i-1][j] + 1

    // dp[i][j] = dp[i-1][j-1] if word1[i] == word1[j] else min(dp[i-1][j]+1,
    // dp[i][j-1]+1);
    int n = word1.length();
    int m = word2.length();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++)
      dp[i][0] = i;
    for (int j = 1; j <= m; j++)
      dp[0][j] = j;

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (word1[i - 1] == word2[j - 1])
          dp[i][j] = dp[i - 1][j - 1];
        // 分别对应三种操作     修改，          插入，          删除
        else
          dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
      }
    }

    return dp[n][m];
  }
};