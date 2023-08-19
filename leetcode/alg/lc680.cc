// leetcode 680
// Valid Palindrome ii

// 给定一串字符串，我们想知道它是否为有效的回文串
// 和Valid Palindrome i 相比，可以允许删除一个字符
// 直接双指针，分别指向首尾
// 然后开始比较，如果遇到不同的时候，我们只能考虑删除左边的字符 或者 删除右边的字符
// 所以直接调用朴素的valid即可
#include <bits/stdc++.h>

using namespace std;
    
class Solution {
public:
    bool valid(string s, int l, int r) {
        while(l < r) {
            if (s[l] != s[r]) return false;
            l ++ ;
            r --;
        }
        
        return true;
    }
    
    bool validPalindrome(string s) {
        int l = 0;
        int r = s.length() - 1;
        
        while(l < r) {
            if (s[l] != s[r]) {
                return valid(s, l+1, r) || valid(s, l, r-1);
            } else{
                l ++;
                r --;
            }
        }
        
        return true;
    }
};