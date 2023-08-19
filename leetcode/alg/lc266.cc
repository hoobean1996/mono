// leetcode 266
// Palindrome Permutation
// 给定一个字符串，问能不能通过排列以后得到一个回文串

// 要形成回文串，左右两端分别相等，那么意味着出现频率为奇数个的字符只能是一个
// 所以我们可以统计字符的频率
// 并利用一个变量count来记录出现频率为奇数次的字符的个数
// 考虑count代表当前的奇数频次的数
// 考虑这个一个数的频次
// v ++ -> 如果从偶数 -> 奇数  if(v % 2 == 1) count ++
// 反之的话，一定有一个奇数 -> 偶数  count --
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canPermutePalindrome(string s) {
        vector<int> v(128, 0);
        int count = 0;
        
        for(int i=0; i<s.length(); i++) {
            v[s[i]] ++;
            
            if (v[s[i]] % 2 == 0) count --;
            else count ++;
        }
        
        return count <= 1;
    }
};