// leetcode 44
// Wildcard Matching

// 星号匹配
// 相比正则表达式匹配来说，*匹配的更多一些

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    bool isMatch(string s, string p) {
        int lens = s.length();
        int lenp = p.length();
        
        
        if (s == p) return true;
        
        // 如果全是*号，肯定是匹配的
        int wildStarCnt = 0;
        for(int i=0; i<lenp; i++) {
            if (p[i] == '*') wildStarCnt++;
        }
        if (wildStarCnt > 0 && wildStarCnt == lenp) return true;
                
        // 如果不全是*号，有任何一个字符串为空，肯定不匹配
        if (lenp == 0 || lens == 0) return false;
        
        // 定义dp[i][j]是长度为i的p前缀和长度为j的s前缀是否match
        vector<vector<bool>> dp = vector<vector<bool>>(lenp + 1, vector<bool>(lens + 1));
        dp[0][0] = true;
        
        for(int pi=1; pi<lenp+1; pi++) {
            // 如果是 * 
            // 尝试找到使得dp[pi-1][si-1]为true的si
            // while((!dp[pi-1][si-1]) && (si < lens + 1)) si++;
            // 1. 存在某个s[i]， 那么 * 可以匹配 si 之后的所有字符 
            // 2. si直到最后也不成立, 那其实当前的*也不会匹配
            if (p[pi-1] == '*') {
                int si = 1;
                while((!dp[pi-1][si-1]) && (si < lens + 1)) si++;
                dp[pi][si-1] = dp[pi-1][si-1];
                while(si < lens + 1) dp[pi][si++] = true;
            }
            else if (p[pi-1] == '?') {
                // 如果是 ?
                // 那么dp[si][si] -> dp[pi-1][si-1] 
                for(int si=1; si<lens + 1; si++) dp[pi][si] = dp[pi-1][si-1];
            }
            else {
                // 都是字符的情况
                // dp[pi][si] = dp[pi-1][si-1] && p[pi-1] == s[si-1]
                for(int si=1; si<lens + 1; si++) {
                    dp[pi][si] = dp[pi-1][si-1] && (p[pi-1] == s[si-1]);
                }
            }
        }
        
        return dp[lenp][lens];
    }
};