// leetcode 91
// Decode Ways

// 考虑把一串字母映射成数字的方法
// 这道题的边界条件最主要的是0
// 一个是0不能作为开始字符，只能和前面的字符连起来
// 二个是数字的范围必须在1-26之间
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        if (s.length() == 0) return 0;
        
        if (s[0] == '0') return 0;
        
        int prev = s[0] - '0';
        // 定义长度为i的解释方案为dp[i]
        
        vector<int> dp(s.length() + 1, 1);
        // 长度为1的情况，只能有一种解释方案
        
        for(int i=2; i<=s.length(); i++) {
            int c = s[i-1] - '0';
            
            if ((prev == 0 || prev > 2) && c == 0) return 0;
            
            if ((prev == 1) || (prev == 2 && c < 7)) {
                if (c != 0) dp[i] = dp[i-1] + dp[i-2];
                else dp[i] = dp[i-2];
            }
            else dp[i] = dp[i-1];
            
            prev = c;
        }
        
        return dp[s.length()];
    }
};