// leetcode 940
// Distinct Subsequences II

// 给定一个字符串，返回该字符串的不同的非空子序列，如果太大 mod 1e9 + 7

// 所有子序列，如果不考虑重复的情况下
// 对于一个长度为I的字符串，总共会有2^I中可能性

// 设置dp[i]表示从头到S[i]这一段形成的不同的子序列
// 在不考虑重复的时候，
// 我们很容易得到一个dp[i] = dp[k-1] * 2
// 如果有重复的话
// [] x [] x
//         i
// x的上一次位置是 last[i]
// 由于last[i]-1之前的方案都会被重复
// dp[i] = 2*dp[i-1] - dp[last[s[i]] - 1]

#include <bits/stdc++.h>

using namespace std;

// The total time complexity O(n)
// The total space complexity O(n)
class Solution {
public:
    int distinctSubseqII(string s) {
        const int n = s.length();
        const int mod = 1e9 + 7;
        
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        vector<int> last(26, -1);
        
        for(int i=0; i<n; i++) {
            int x = s[i] - 'a';
            dp[i+1] = dp[i] * 2  % mod;
            if (last[x] >= 0) dp[i+1] -= dp[last[x]];
            dp[i+1] %= mod;
            last[x] = i;
        }
        
        dp[n] --;
        
        if (dp[n] < 0) dp[n] += mod;
        return dp[n];
    }
};

// 优化到O(1)空间复杂度的解法
class Solution {
public:
    int distinctSubseqII(string s) {
        int MOD = 1e9+7;

        int pre = 1;//The number of subsequences till previous-location. Include empty string: ""
        int cur = 1;//The number of subsequences till now. Include empty string: ""
        vector<int> lastCount(26, 0); //The number of subsequences that end with a character till now. Not include empty string: ""
        for(int i=0; i<s.length(); ++i)
        {
            int charIndex = s[i] - 'a';
            cur = pre * 2 % MOD;//include-current-character  +  not-include-current-character
            cur -= lastCount[charIndex];//Remove duplicated characters: previous subsequences that end with current character.
            cur = cur >= 0 ?  cur%MOD : cur+MOD;
            lastCount[charIndex] = pre; //The number of subsequences that end with current character.
            pre = cur;
        }
        --cur;// remove the empty string: ""
        return cur;        
    }
};