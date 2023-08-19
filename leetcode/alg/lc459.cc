// leetcode 459
// Repeated Substring Pattern 
// 给定一个字符串，判断它是否由多个子串反复拼接而成

#include <bits/stdc++.h>

using namespace std;


// 一种办法就是枚举可能的字串并判断是否是由他们拼接而成
// 另外一种办法是转换为求字符串的最小周期，而最小周期可以利用pi前缀函数
// 来实现
class Solution {
public:
    vector<int> next(string s) {
        vector<int> pi(s.length(), 0);

        for (int i = 1; i < s.length(); i++) {
            int j = pi[i - 1];
            while (j > 0 && s[i] != s[j]) j = pi[j - 1];
            if (s[i] == s[j]) j++;
            pi[i] = j;
        }

        return pi;
    }

    bool repeatedSubstringPattern(string s) {
        vector<int> pi = next(s);
        // 若r < len(s)
        // 如果r长度的前缀和r长度的后缀相等，那么称r是字符串的border
        // 若字符串s有border r，当且仅当有周期 |s| - r
        // s[1..r] = s[n-r+1, n]
        // s[x] = s[x+n-r] -> 周期的定义
        // 所以有border r等价于有周期|s| - r
        int r = pi[s.length() - 1];
        int len = s.length() - r;
        return len < s.length() && s.length() % len == 0;
    }
};