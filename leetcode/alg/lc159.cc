// leetcode 159
// longest substring at most two distinct characters
// 给定一个字符串，我们想要找到其中的一个子串，在这个子串中最多有两个不同的字符
// 还是一样的，维护一个区间 [l, r] 代表满足条件的区间
// 维护一个区间，count代表不同的字符的数量, m来记录每个字符的个数
// [l, r] 
// 每遇到一个字符，我们就 m[c] ++ -> 如果当前的m[c] 是1，证明是一个新的字符
// 每当count > 3，我们就移动左指针 m[s[l]] --, 如果当前的 m[s[l]] == 0证明这个字符没有了, count --
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int n = s.length();
        if (n < 3) return n;
        
        int ans = 0;
        int l = 0;
        int count = 0;
        map<char, int> m;

        for(int r =0; r<s.size(); r++) {
            m[s[r]] ++;

            if (m[s[r]] == 1) count ++;

            while(count > 3) {
                m[s[l]] --;
                if (m[s[l]] == 0) count --;
                l ++;
            }

            ans = max(ans, r - l + 1);
        }
    }

    return ans;
};