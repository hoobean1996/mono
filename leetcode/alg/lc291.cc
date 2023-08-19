// leetcode 291
// word pattern II
// 给定一个字符串s，和一个模式串p
// 如果字符串s满足模式p那么就是返回true
// 比如模式串是AABB，那么字符串就可以写为对应的模式
// 由于我们并不清楚字符串s中的子串和模式串的对应情况，所以需要枚举+回溯
// 考虑两个指针，分别指向字符串s，和模式串p
// 尝试不断的划分字符串成不同的部分来进行匹配

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    unordered_map<char, string> m;
    
    // backtrack返回两个字符串是否存在某种一致的pattern
    bool backtrack(string pattern, int i, string str, int j) {
        // 由于我们使用的是双指针，所以当两个指针都到底的时候，就返回true即可
        if (i == pattern.length() && j == str.length()) return true;
        
        // 如果某个已经到底，但是另外一个还没有到底，证明该方案不行 返回false
        if (i == pattern.length() || j == str.length()) return false;
        
        // 当前的字符 c
        char c = pattern[i];
        
        for(int k=j; k<str.length(); k++) {
            // 当前的子串是 sub: j .. k
            string sub = str.substr(j, k-j+1);
            
            // 整体的思路是先考虑字符的匹配情况
            // 然后在考虑字符串的匹配情况

            // 如果当前的字符已经和某个字符串匹配
            // 我们需要检查这个字符串是否就是当前的sub
            // 如果是，就继续处理剩余的
            // 如果不是，那么就增长字符串，尝试更多
            if (m.count(c)) {
                if (m[c] == sub) {
                    if (backtrack(pattern, i+1, str, k+1)) return true;
                }
                else continue;
            }
            // 该字符没有和任何字符串匹配
            // 我们需要反向检查当前字符串和任何字符匹配吗？
            else {
                bool matched = false;
                
                for(auto it: m) {
                    if (it.second == sub) {
                        matched = true;
                    }
                }
                // 如果已经有某个字符和该字符串匹配，那么我们也应该继续增加字符串来避免该
                // 字符串和两个字符匹配
                if (matched) continue;
                // 如果没有匹配，那么我们尝试匹配 c -> sub, 然后递归的尝试
                else {
                    m[c] = sub;
                    if (backtrack(pattern, i+1, str, k+1)) return true;
                    m.erase(c);
                }
            }
        }
        
        return false;
    }
    
    bool wordPatternMatch(string pattern, string s) {
        return backtrack(pattern, 0, s, 0);
    }
};