// leetcode 87
// Scramble String 
// 定义dp[i][j][k]代表
// s[i...i+len]
// t[j...j+len]
// 这两个字符串是否为Scramble String

class Solution {
    public:

    bool isScramble(string s1, string s2) {
        // 如果长度不一致，肯定不是
        if (s1.length() != s2.length()) return false;
        
        // 如果完全一样，肯定是
        if (s1 == s2) return true;

        int n = s1.length();

        vector<vector<vector<bool>>> dp(n, vector<vector<bool>>(n, vector<bool>(n+1, false)));

        for(int k=1; k<=n; k++) {
            for(int i=0; i<=n-k; i++) {
                for(int j=0; j<=n-k; j++) {
                    // 如果长度为1， 那么两个字符串是 scramble的条件是必须相同
                    if (k == 1) dp[i][j][k] = s1[i] == s2[j];
                    else {
                        // 否则的话，我们需要枚举一个长度，尝试把这个长度划分为两段
                        // 然后判断两个子串是否为scramble的
                        for(int p=1; p<k; p++) {
                            // 如果存在一个点满足，那么dp[i][j] 就是true
                            if ((dp[i][j][p] && dp[i+p][j+p][k-p]) || (dp[i+p][j][k-p] && dp[i][j+k-p][p])) dp[i][j][k] = true;
                        }
                    }
                }
            }
        }

        return dp[0][0][n];
    }
};