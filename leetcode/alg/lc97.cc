// leetcode 97
// Interleaving String

class Solution
{
public:
    bool isInterleave(string s1, string s2, string s3)
    {
        int l1 = s1.length();
        int l2 = s2.length();
        int l3 = s3.length();

        if (l1 + l2 != l3) return false;

        // 定义dp[i][j]表示
        // s3的长度为i+j+2的前缀是否可以由
        //  s1长度为i+1的前缀
        //  s2长度为j+1的前缀
        // 构成
        vector<vector<bool>> dp = vector<vector<bool>>(l1 + 1, vector<bool>(l2 + 1, false));

        for (int i = 0; i <= s1.length(); i++)
        {
            for (int j = 0; j <= s2.length(); j++)
            {   
                // 长度为0的时候，肯定是可以的
                if (i == 0 && j == 0)
                    dp[i][j] = true;
                // i == 0 的时候，相当于全部由s2的字符串构成
                // dp[i][j] == dp[i][j-1] && s2[j-1] == s3[i+j-1];
                else if (i == 0)
                {
                    dp[i][j] = dp[i][j - 1] && s2[j - 1] == s3[i + j - 1];
                }
                // j == 0 的时候，相当于全部由s1的字符串构成
                // dp[i][j] == dp[i-1][j] && s1[i-1] == s3[i+j-1]
                else if (j == 0)
                {
                    dp[i][j] = dp[i - 1][j] && s1[i - 1] == s3[i + j - 1];
                }
                // 其他情况
                // 1. dp[i-1][j] && s1[i-1] == s3[i+j-1] 这个字符来自于s1
                // 2. dp[i][j-1] && s2[j-1] == s3[i+j-1] 这个字符来自于s2  
                else
                {
                    dp[i][j] = (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]) || (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
                }
            }
        }

        return dp[l1][l2];
    }
};