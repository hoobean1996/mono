// leetcode 767
// Reorganing String 

// 给定一个字符串，通过重新排列字符的位置来得到一个任意两个连续字符都不相同的新的字符串
// 如果不能得到，返回 ""

// 首先考虑出现频率最多的字符串，如果大于一半的话，肯定是不能满足的
// 然后我们考虑如何重排
// 1. 从第一个位置间隔的先把频率最多的字符串放好
// 2. 然后在一次放好第二个字符
// 每次都是间隔一个
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string reorganizeString(string s) {
        vector<int> count(26, 0);
        // 出现最多次的字符
        int mostFreqChar = 0;

        for(const char c: s) {
            count[c - 'a'] ++;
            if (count[c - 'a'] > count[mostFreqChar]) mostFreqChar = c - 'a';
        }

        // 如果超过的次数大于一半，肯定是不行的
        if (2 * count[mostFreqChar] - 1 > s.length()) return "";

        // 由于频率最多的元素可能不到一半，所以不一定能占完
        // 从 0 开始 0 2 4 。。 开始放置字符
        int i = 0;
        while(count[mostFreqChar]) {
            s[i] = ('a' + mostFreqChar);
            i += 2;
            count[mostFreqChar] --;
        }

        // 继续接着上面的占位置，如果超过了最大位置，那么重置到1
        // 然后同样的逻辑填充即可
        for(int j=0; j<26; j++) {
            while(count[j]) {
                if (i >= s.length()) i = 1;
                s[i] = ('a' + j);
                count[j] --;
                i += 2;
            }
        }

        return s;
    }
};