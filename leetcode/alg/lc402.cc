// leetcode 402
// Remove K Digits
// 给定一个数字字符串，和一个数字k，我们想知道在从字符串中删除k个数字以后
// 得到的最小的值是多少
// 也就是说在保持相对位置不变的情况下，我们要把较小的数往前提
// 换句话说，然后我们要把左边较大的数都删了
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        // 创建一个栈
        stack<char> sk;
        
        // 单调递增栈
        // 尽量把比他大的数都删除掉，不超过k次
        for(int i=0; i<num.size(); i++) {
            while(!sk.empty() && k>0 && sk.top() > num[i]) {
                sk.pop();
                k -= 1;
            }
            sk.push(num[i]);
        }
        
        // 如果已经是递增的了，但是没有删到k次
        // 所以还需要弹出几次
        for(int i=0; i<k; i++) sk.pop();
        
        // 考虑把结果从栈转换为字符串
        string s;
        while(!sk.empty()) {
            s += sk.top();
            sk.pop();
        }
        reverse(begin(s), end(s));

        // 忽略前置的0        
        string ans;
        bool leadingZero = true;
        
        for(const char c: s) {
            if (leadingZero && c == '0') continue;
            leadingZero = false;
            ans += c;
        }
        
        if (ans == "") return "0";
        
        return ans;
    }
};