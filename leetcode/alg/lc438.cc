// leetcode 438
// Find All Anagrams in a String 
// 给定一个大字符串s和小的字符串p，我们希望在大字符串中找到所有小字符串的重排列。

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.length();
        int m = p.length();
        
        if (n < m) return {};
        
        vector<int> pCount(26, 0);
        vector<int> sCount(26, 0);
        
        // 首先统计字谜的频次信息
        for(const char c: p) pCount[(int)(c - 'a')] ++;
        
        vector<int> ans;
        
        // 维护一个长度和p相同的区间，
        // 统计当前的字符的个数
        // 由于anagram是p的重排列，所以只需要关注于个数
        for(int i=0; i<n; i++) {
            sCount[(int)(s[i] - 'a')] ++;
            // 维护的区间是固定的长度 == m
            // 每次超过的时候，就把最左边的那个字符的频次减一
            if (i >= m) sCount[(int)(s[i - m] - 'a')] --;
            // 比较当前的区间是否和字谜的信息一样
            if (sCount == pCount) ans.push_back(i - m + 1);
        }
        
        return ans;
    }
};