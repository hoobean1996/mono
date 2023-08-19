// leetcode 224
// Basic Calculator

// 符号包含 + - ()
// 考虑表达为 +a +b +c .. 的模型
// 如果遇到一个数字，我们直接把它和之前的sum相加
// 如果遇到括号，我们把当前的和入栈，然后开始计算括号内的。
// 定义的sum实际上是当前没有括号的那层的和
// 考虑最简单的case，就是没有括号的情况
// sum = 0
// sign = 1
// 遇到数字 就累计到sum上
// 遇到 + / - 就更新sign
// 但是由于有了括号，优先级是会改变的，所以我们就把当前的情况存起来，然后计算下一层的即可
// 最后一起计算
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int calculate(string s) {
        int n = s.length();
        if (n == 0) return 0;

        int sign = 1;
        int sum = 0;
        stack<int> sk;

        int i = 0;

        while(i < n) {
            // 解析数字
            if (isdigit(s[i])) {
                int num = 0;
                while(i < n && isdigit(s[i])) {
                    num = num * 10 + (s[i] - '0');
                    i ++;
                }
                i --;
                sum += num * sign;
            }
            else if (s[i] == '+') sign = 1;
            else if (s[i] == '-') sign = -1;
            else if (s[i] == '(') {
                sk.push(sum);
                sk.push(sign);
                sum = 0;
                sign = 1;
            }
            else if (s[i] == ')') {
                sum = sk.top() * sum; sk.pop();
                sum += sk.top(); sk.pop();
            }
            i ++;
        }

        return sum;
    }
};