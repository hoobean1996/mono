// leetcode 227
// Basic Calculator II

// 符号包含 + - * / 空格 这道题是没有括号的
// 这道题只是优先级不同，括号还有一个延迟计算的效果，就是得先算括号里面的值，然后才配合上
// 前面的符号才能知道结果
// 但是这道题的优先级不同，但是是可以立即求值的
// op = +
// curNumber = 0
// 如果遇到数字，就更新curNumber，然后continue即可
// 如果遇到符号，我们就需要考虑处理之前的符号，然后在更新为当前的符号
//     如果是 - 我们就把 -curNumber 放入到栈中
//     如果是 + 我们就把 +curNumber 放入到栈中
//     如果是 * 那么就应该把上一个数弹出u, 计算 u * curNumber 并入栈
//     如果是 / 那么久应该把上一个数弹出u, 计算 u / curNumber 并入栈

// 和224的区别（224是有括号的）
// （括号是对后面的元素生效
// 而 * / 是需要对符号前面的元素生效
// 所以对于224，我们直接处理当前的符号即可
// 而对于227，我们需要考虑之前的符号
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int calculate(string s) {
        int n = s.length();
        if (n == 0) return 0;
        
        stack<int> sk;
        int curNumber = 0;
        char op = '+';
        
        int i = 0;
        while(i < n) {
            char c = s[i];
            if (isdigit(s[i])) {
                while(i < n && isdigit(s[i])) {
                    curNumber = curNumber * 10 + (s[i] - '0');
                    i ++;
                }
                i --;
            }
            // 如果是数字 解析完了以后 就继续下一个
            // 如果是符号的话，就需要处理之前的数字和符号
            // 然后在更新
            if (!isdigit(c) && !iswspace(c) || i == n-1) {
                // 这里是说curNumber之前的符号
                if (op == '-') sk.push(-curNumber);
                else if (op == '+') sk.push(curNumber);
                else if (op == '*') {
                    int u = sk.top();
                    sk.pop();
                    sk.push(u * curNumber);
                }
                else if (op == '/') {
                    int u = sk.top();
                    sk.pop();
                    sk.push(u / curNumber);
                }
                op = c;
                curNumber = 0;
            }
            i ++;
        }
        
        int ans = 0;
        while(!sk.empty()) {
            ans += sk.top();
            sk.pop();
        }
        return ans;
    }
};

// 考虑优化栈的使用
// 由于我们每次只使用栈顶的值，所以可以优化的
// S代表已经累计的和
// last代表当前正在计算的数，因为有*/的存在，它可能还没有计算完成
// cur代表当前的数
// op = +
// 如果遇到数字的话，那么我们只需要把cur更新即可，然后跳过
// 如果遇到符号的话，那么就需要考虑处理之前的符号
//   如果是 + 或者 - 那么就可以更新结果为 S += last 并更新last = cur
//   如果是 * / 还是更新last = last * cur
// 
class Solution {
public:
    int calculate(string s) {
        int n = s.length();
        if (n == 0) return 0;
        
        int S = 0;
        int last = 0;
        int cur = 0;
        char op = '+';
        
        int i = 0;
        
        while(i < n) {
            // 解析当前的数字
            if (isdigit(s[i])) {
                int num = 0;
                while(isdigit(s[i])) {
                    num = num * 10 + (s[i] - '0');
                    i ++;
                }
                cur = num;
                i --;
            }
            
            if (!isdigit(s[i]) && !iswspace(s[i]) || i == n-1) {
                if (op == '+' || op == '-') {
                    S += last;
                    // 由于遇到符号的时候不会改变cur，
                    // 所以这里的cur就是上一个数
                    last = op == '+' ? cur : -cur;
                }
                else if (op == '*') last = last * cur;
                else if (op == '/') last = last / cur;
                
                op = s[i];
                cur = 0;
            }
            i ++;
        }
        
        S += last;
        
        return S;
    }
};