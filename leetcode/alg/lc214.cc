// leetcode 214
// Shortest Palindrome
// 给定一个字符串s，通过添加字符到前面来把它变成一个回文串

// 考虑字符串aacecaaa
// 及其反转的字符串 aaacecaa
// 我们会发现
// s = [aacecaa]a
// s' = a[aacecaa]
// 所以结果是 a + [aacecaa]a 即可
// 本质上是求最长回文前缀，我们利用KMP中求解pi数组来求解
// 将s + "#" + s'拼接起来，直接求解pi数组，
// 我们需要知道的是结尾在i-1的最长匹配长度是多少
// rev.substr(0, n-f[len-1]) + s即可

// 计算pi数组的模版
// vector<int> next(string s) {
//     int n = s.length();
//     vector<int> pi(n, 0);
//     // pi[0] = 0
    
//     for(int i=1; i<n; i++) {
//         int j = pi[i-1];
//         while(j > 0 && s[i] != s[j]) {
//             j = pi[j-1];
//         }
//         if (s[i] == s[j]) j++;
//         pi[i] = j;
//     }
    
//     return pi;
// }

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // 首先通过拼接s和s的反转字符串
    // 构造一个字符串，t = s + # + s'
    // 求解它的kmp数组
    // 就能知道它的最长匹配前缀了
    string shortestPalindrome(string s) {
        int n = s.length();
        string rev(s);
        reverse(rev.begin(), rev.end());
        string s_new = s + "#" + rev;
                
        int n_new = s_new.size();
        vector<int> pi(n_new, 0);
        for(int i=1; i<n_new; i++) {
            int j = pi[i-1];
            while(j > 0 && s_new[i] != s_new[j]) j = pi[j-1];
            if (s_new[i] == s_new[j])
                ++j;
            pi[i] = j;
        }
        
        return rev.substr(0, n-pi[n_new-1]) + s;
    }
};