// leetcode 921
// Minimum Add to Make Parentheses Valid

// 给定一个符号序列
// 我们可以在任意位置插入一个( or )
// 请问为了让该括号序列有效需要的最小插入的次数是多少
// 遍历字符串的时候维护左括号的数量，如果遇到右括号的时候，去看是否有足够的左括号，如果左括号不够的话，
// 就需要添加一个左括号 ans ++ 
// 最后需要考虑的是如果左括号过多的话，还需要 ans += l
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minAddToMakeValid(string s) {
        if (s.length() == 0) return 0;
        
        int l = 0;
        int r = 0;
        
        int ans = 0;
        
        for(int i=0; i<s.length(); i++) {
            if (s[i] == '(') l ++;
            else if (s[i] == ')') {
                if (l > 0) l --;
                else ans ++;
            }
        }
        
        if (l > 0) ans += l;
        
        return ans;
    }
};