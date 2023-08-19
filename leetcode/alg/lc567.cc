// leetcode 567
// Permutation in String
// 给定两个字符串s1和s2，如果字符串s2包含字符串s1的任何一个排列，就返回true
// 否则的话就返回false

#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    // 判断字符串p的排列是否在字符串s中出现
    // 由于我们只关心的是排列，所以可以通过统计频率来确保每个字符都存在就可以了
    // n -> len(s)
    // m -> len(p)
    // 如果s都不够长的话，肯定是不可能的
    // 遍历字符串p，统计得到对应的频次信息
    // 然后我们遍历字符串s，维护一个长度为m的区间
    // 每访问一个字符，就把对应字符的频次 ++
    // 如果长度过长了，就把第一个左指针的位置的对应的字符频次 --
    // 每次都判断两个频次是否完全一致，如果一样的话，证明在这个区间就包含了p字符串的一个排列
    bool checkInclusion(string p, string s) {
        int n = s.length();
        int m = p.length();
        
        if (n < m) return false;
        
        vector<int> pCount(26, 0);
        vector<int> sCount(26, 0);
        
        for(const char c: p) pCount[(int)(c - 'a')] ++;
        
        for(int i=0; i<n; i++) {
            // 相当于维护了长度为p的区间
            sCount[(int)(s[i] - 'a')] ++;
            
            // 如果大于该区间的长度，我们需要把移动左指针
            if (i >= m) sCount[(int)(s[i - m] - 'a')] --;

            if (sCount == pCount) return true;
        }
        
        return false;
    }
};