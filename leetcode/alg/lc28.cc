// leetcode 28
// Implement strStr

// 就是字符串匹配的基本问题
// 我们可以构造一个字符串 needle + "#" + haystack
// 然后计算出pi数组
// 如果存在某个pi[j] = len(needle)
// 那么就证明找到了那个位置
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> next(string s) {
        int n = s.length();
        vector<int> pi(n, 0);
        
        for(int i=1; i<n; i++) {
            int j = pi[i-1];
            while(j > 0 && s[i] != s[j]) {
                j = pi[j-1];
            }
            if (s[i] == s[j]) j++;
            pi[i] = j;
        }
        
        return pi;
    }
    
    int strStr(string haystack, string needle) {
        int n = haystack.length();
        int m = needle.length();
        string s = needle + "#" + haystack;
        
        vector<int> pi = next(s);
                
        for(int i=0; i< pi.size(); i++) {
            if (pi[i] == m) return i - 2*m;
        }
        return -1;
    }
};