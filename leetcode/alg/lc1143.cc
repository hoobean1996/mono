// leetcode 1143
// Longest Common Subsequence

// 给定两个字符串，我们想知道两个字符串的最长公共子序列的长度
// 方法一是基于动态规划
// 我们定义dp[i][j]是长度为i的A字符串和长度为j的B字符串的最长公共子序列的长度
// 如果A[i-1] == B[j-1] -> 那么dp[i][j] = dp[i-1][j-1] + 1
// 否则的话 那么dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + 1
// 时间复杂度是O(n^2)
// 空间复杂度是O(n)

// 方法二：对于A，B两个字符串，我们把A中的每个字符替换成在B中出现的位置的逆序列
// 比如 A = abacd
//     B = cabbab

// 字符a的位置是(2,5), 字符b的位置的(3,4,6) ...
// 把A序列替换成(5,2) (6,4,3), (1), ()
// 由于匹配是递增的，每个括号里面必须选一个，选出来的数也必须递增
// 这样就把最长公共子序列转换成了最长递增子序列的问题
// 利用贪心 + 二分可以在O(nlgn)解决
// 参考leetcode 300

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // 求解最长公共序列
    int longestCommonSubsequence(string s1, string s2) {
        
        // 定义dp[i][j]是 s1的长度为i的前缀和s2长度为j的前缀的最长公共子序列的长度
        int m = s1.length();
        int n = s2.length();
        
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

        for(int i=1; i<=m; i++) {
            for(int j=1; j<=n; j++) {
                // 注意字符的下表是i-1, j-1
                // dp的范围是i, j
                if (s1[i-1] == s2[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        
        // 时间复杂度为O(mm)
        return dp[m][n];
    }
};