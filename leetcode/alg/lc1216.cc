// leetcode 1216
// Valid Palindrome III

// 字符串最多删除k个字符能变成回文
// 最多删除k个字符，等价于存在一个回文序列
// 假设dp[i][j]表示[i .. j]最长的回文子序列长度
// 当s[i] == s[j]的时候，dp[i][j] = dp[i+1][j-1] + 2
// dp[i][i] 都是1 
// i = n-1 ... =0
//  j = i+1 .. <n
//      dp[i][j] = dp[i+1][j-1] + 2 if s[i]==s[j] else max(dp[i+1][j], dp[i][j-1])
// 可以在O(n^2)构造出dp表
// dp[0][n-1]表示在0..n-1中最长的回文子序列，如果它的长度l + k >= n那么肯定是可以的

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isValidPalindrome(string s, int k) {
        const int n = s.length();

        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int i=0; i<n; i++) dp[i][i] = 1;

        for(int i=n-1; i>=0; i--) {
            for(int j=i+1; j<n; j++) {
                if (s[i] == s[j]) dp[i][j] = dp[i+1][j-1] + 2;
                else dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
            }
        }

        return n - dp[0][n-1] <= k;
    }
};