// leetcode 340
// Longest Substring with At Most k Distinct Characters

// 维护闭区间 [l, r] 满足条件
// while(r < n)
// 尝试加入该字符，如果超过了k的限制，删除最左的字符，并移动l
// 利用一个map来记录每个字符出现的次数
// 每遇到一个字符，就把对应的字符频次加1
// 如果该字符的频次为1的话，那么就把不同的字符数目+1
// 如果当前的count > k
//  我们就不断的把l的频次-1，如果该频次为0的话，我们也需要把不同的字符数目-1
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int n = s.length();

        int ans = 0;
        int l = 0;
        int count = 0;
        map<char, int> m;

        for(int r=0; r<s.size(); r++) {
            m[s[r]] ++;

            if (m[s[r]] == 1) count ++;

            while(count > k) {
                m[s[l]] --;
                if (m[s[l]] == 0) count --;
                l ++;
            }

            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};