// leetcode 65
// Valid Number 

// 我们三种关键的状态变量
// 通过遍历字符串，来设置这几个变量，同时根据状态来排除不合法的情况
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isNumber(string s) {
        bool seenDigit = false;
        bool seenExponent = false;
        bool seenDot = false;
        
        for(int i=0; i<s.length(); i++) {
            char c = s[i];
            // 如果遇到一个数字，标记为true
            if (isdigit(c)) seenDigit = true;
            // 如果在非第一个字符遇到 +, - ，无效
            else if (c == '+' || c == '-') {
                if (!(i == 0 || (i > 0 && (s[i-1] == 'e'  || s[i-1] == 'E')))) return false;
            }
            // 如果已经遇到e, E过，或者还没有遇到数字，无效
            else if (c == 'e' || c == 'E') {
                if (seenExponent || !seenDigit) return false;
                seenExponent = true;
                // seendDigit 初始化为false，因为需要等待E,e之后在次遇到数字
                seenDigit = false;
            }
            // 如果遇到过. 或者遇到过e, E 无效（因为不允许小数指数)
            else if (c == '.') {
                if (seenDot || seenExponent) return false;
                seenDot = true;
            }
            // 其他字符都是无效
            else return false;
        }
        
        return seenDigit;
    }
};