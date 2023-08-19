// leetcode 10
// Regular Expression Matching

#include <bits/stdc++.h>

using namespace std;

bool isMatch(string s, string p) {
  int lens = s.length();
  int lenp = p.length();

  // 定义dp[i][j] 代表s前缀长度为i的字串和p前缀长度为j的字串是否匹配
  vector<vector<bool>> dp(lens + 1, vector<bool>(lenp + 1, false));

  // 初始条件
  dp[0][0] = true;

  for (int j = 1; j <= lenp; j++)
    dp[0][j] = p[j - 1] == '*' && dp[0][j - 2];

  // 考虑模式串的某个字符的复杂程度
  // 1. 和匹配串的完全相同，都是字符
  // 2. . 这个符号可以和任意字符匹配
  // 3. * 这个符号需要考虑前一个字符
  for (int i = 1; i <= lens; i++) {
    for (int j = 1; j <= lenp; j++) {
      // 如果当前两个字符相等
      if (p[j - 1] == s[i - 1])
        dp[i][j] = dp[i - 1][j - 1];
      // 如果两个字符不等，但是当前的是.，由于它可以匹配任意的字符，所以和上面等价
      else if (p[j - 1] == '.')
        dp[i][j] = dp[i - 1][j - 1];
      // 如果两个字符不等，并且当前是*
      else if (p[j - 1] == '*') {
        // x* 如果*前面的字符和s[i-1]不相等
        // .* 或者*前面的字符是.
        // 这两种情况都是匹配的，如果不匹配，那么就应该相当于不考虑p的后两个字符
        if (p[j - 2] != s[i - 1] && p[j - 2] != '.')
          dp[i][j] = dp[i][j - 2];

        else
          dp[i][j] = (dp[i][j - 1] || dp[i - 1][j] || dp[i][j - 2]);
      } else
        dp[i][j] = false;
    }
  }

  return dp[lens][lenp];
}