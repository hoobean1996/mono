// leetcode 772
// Basic Calculator III

// 什么说后缀表达式最容易被计算机理解呢？
// 因为后缀表达式不需要括号表示，它的运算顺序是唯一确定的。
// 举个例子：在后缀表达式  中，首先计算 （使用最后一个运算符，即栈顶运算符），然后计算 。
// 对于一个后缀表达式，只需要 维护一个数字栈，每次遇到一个运算符，就取出两个栈顶元素，将运算结果重新压入栈中。
// 最后，栈中唯一一个元素就是该后缀表达式的运算结果时间复杂度 。

// 所以说，对于普通中缀表达式的计算，我们可以将其转化为后缀表达式再进行计算
// 转换方法也十分简单。只要建立一个用于存放运算符的栈，扫描该中缀表达式：
// 如果遇到数字，直接将该数字输出到后缀表达式（以下部分用「输出」表示输出到后缀表达式）；
// 如果遇到左括号，入栈；
// 如果遇到右括号，不断输出栈顶元素，直至遇到左括号（左括号出栈，但不输出）；
// 如果遇到其他运算符，不断去除所有运算优先级大于等于当前运算符的运算符，输出。最后，新的符号入栈；
// 把栈中剩下的符号依次输出，表达式转换结束。

// 数字 输出
// ( -> 入栈
// ） 一直出栈直到（
// op -> 不断去除优先级更高的运算符，然后入栈
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string infix2suffix(string s) {
        stack<char> sk;

        string suffix;

        for(int i=0; i<s.length(); i++) {
            if (isdigit(s[i])) {
                while(isdigit(s[i])) {
                    suffix += s[i];
                    i ++;
                }
                i --;
                suffix += " ";
            }
            else if (s[i] == '(') sk.push(s[i]);
            else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
                if (s[i] == '+' || s[i] == '-') {
                    while(!sk.empty() && (sk.top() == '*' || sk.top() == '/' || sk.top() == '+' || sk.top() == '-')) {
                        suffix += sk.top();
                        suffix += " ";
                        sk.pop();
                    }
                }
                else if (s[i] == '*' || s[i] == '/') {
                    while(!sk.empty() && (sk.top() == '*' || sk.top() == '/')) {
                        suffix += sk.top();
                        suffix += " ";
                        sk.pop();
                    }
                }
                sk.push(s[i]);
            }
            else if (s[i] == ')') {
                while(!sk.empty()) {
                    char u = sk.top();
                    if (u != '(') {
                        suffix += u;
                        suffix += " ";
                        sk.pop();
                    }
                    else {
                        sk.pop();
                        break;
                    }
                }
            }
        }

        while(!sk.empty()) {
            suffix += sk.top();
            suffix += " ";
            sk.pop();
        }

        return suffix;
    }
    
    int cal(string s) {
        stack<int> sk;

        int i = 0;
        while(i < s.length()) {
            if (s[i] == ' ') {
                i ++;
                continue;
            }
            else if (isdigit(s[i])) {
                int sum = 0;
                while(s[i] != ' ') {
                    sum = sum * 10 + (s[i] - '0');
                    i ++;
                }
                sk.push(sum);
            }
            else {
                if (s[i] == '+') {
                    int u = sk.top(); sk.pop();
                    int v = sk.top(); sk.pop();
                    sk.push(v + u);
                }
                else if (s[i] == '-') {
                    int u = sk.top(); sk.pop();
                    int v = sk.top(); sk.pop();
                    sk.push(v - u);
                }
                else if (s[i] == '*') {
                    int u = sk.top(); sk.pop();
                    int v = sk.top(); sk.pop();
                    sk.push(v * u);
                }
                else if (s[i] == '/') {
                    int u = sk.top(); sk.pop();
                    int v = sk.top(); sk.pop();
                    sk.push(v / u);
                }
                i ++;
            }
        }
        return sk.top();
    }
    
    int calculate(string s) {
        string suffix = infix2suffix(s);
        return cal(suffix);
    }
};