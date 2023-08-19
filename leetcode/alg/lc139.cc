// leetcode 139
// word break
// 给定一个字符串和一个字典，如果这个字符串能够被划分为字典中的词相连而成
// leetcode leet, code
// 就返回true，否则返回false
// 定义dp[i]代表长度为i的子串是否能够被break
// 如果在i之前由一个位置j满足 dp[j] == true and s[i..j]在字典中能找到的话，那么dp[i] = true
// 所以我们就在i之前枚举所有的j，来寻找是否有满足条件的j
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.length() + 1);
        dp[0] = true;
        
        for(int i=1; i<=s.length(); i++) {
            for(int j=0; j<i; j++) {
                string sub = s.substr(j, i-j);

                if (dp[j] && wordSet.count(sub)){
                    dp[i] = true;
                    break;
                }
            }
        }
        
        return dp[s.length()];
    }
};