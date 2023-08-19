// leetcode 115
// Distinct Subsequences

// 给定一个字符串，求不同的子序列的个数（这些子序列需要等于另外一个字符串

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        int l1=s.size();
        int l2=t.size();
        // 如果给定的另外一个字符串更长，那么肯定是无解的
        if(l2>l1) return 0;

        // 定义dp[i][j]是字符串 长度为i的子序列是长度为j的字符串的个数
        vector<vector<unsigned int>> dp(l1+1, vector<unsigned int>(l2+1, 0));
       
        // 两个空字符串答案为1
        dp[0][0]=1;
        
        // 任意字符串都有一个空串，所以至少是1
        for(int i=0;i<=l1;i++) dp[i][0]=1;

        for(int i=1;i<=l1;i++)
        {
            for(int j=1;j<=l2;j++)
            {
                if(j>i) continue;
                // 首先可以明确的是 dp[i][j] = dp[i-1][j] 至少等于这么多
                // 因为是子序列，我们可以忽略新的这个值
                dp[i][j] = dp[i-1][j] + (s[i-1]==t[j-1] ? dp[i-1][j-1] : 0);
            }
        }
        return dp[l1][l2];
    }
};