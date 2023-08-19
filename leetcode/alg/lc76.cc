// leetcode 76
// Minimum Window Substring
// 给定两个字符串，s和t
// 返回最小的一个s的子串，在这个子串中t中的每个字符都在这个子串中出现了
// 比如ADOBECODEBANC ABC 
// 返回BANC即可  
// 基本上是需要统计频率的
// 首先遍历t字符串，统计每个字符串的概率
// flag代表出现过某个字符
// chars 代表某个字符出现的次数
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> chars(128, 0);
        vector<bool> contains(128, false);
        
        for(int i=0; i<t.length(); i++) {
            contains[t[i]] = true;
            ++chars[t[i]];
        }
        
        int cnt = 0;
        int l = 0;
        int min_l = 0;
        int min_size = s.length()  + 1;
        
        // 维护一个区间[l, r]
        // 如果当前的字符s[r]出现过
        for(int r = 0; r < s.length(); r++) {
            if (contains[s[r]]) {
                // 还不够t中对应的字符个数，就++cnt
                if (--chars[s[r]] >= 0) ++cnt;
                
                // 只要cnt的数量比t的总字符数还要多
                // 那么就应该考虑移动l
                while (cnt >= t.length()) {
                    if (r - l + 1 < min_size) {
                        min_l = l;
                        min_size = r - l + 1;
                    }
                    // 如果出现过该字符，
                    if (contains[s[l]] && ++chars[s[l]] > 0) cnt --;
                    ++ l;
                }
            }
                
        }
        
        return min_size  > s.length()? "" : s.substr(min_l, min_size);
    }
};