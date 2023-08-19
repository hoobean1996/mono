// leetcode 392
// Is Subsequence
// 判断一个字符串是否为另外一个字符串的子序列
// 利用两个指针，由于是子序列
// 所以相同的时候，同时移动
// 不同的时候，只移动其中一个指针即可，最后判断是否都走到最后一个位置
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0;
        int j = 0;
        
        while(i < s.length() && j < t.length()) {
            if (s[i] == t[j]) {
                i ++;
                j ++;
            }
            else j ++;
        }
        
        if (i != s.length()) return false;
        return true;
    }
};