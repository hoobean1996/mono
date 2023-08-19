// leetcode 301
// Remove Invalid Parentheses

// 删除无效的括号，这道题是说我们有一串括号，但是包括了一些不匹配的
// 括号，我们需要删除它们，然后剩余的是合法的括号序列。
// 然后输出所有的方案
// 1. 首先我们可以计算出不匹配的字符个数
// 2. 回溯 算法 每次删除当前的字符
//   回溯的终止条件： 1. 已经搜索过了， 2. 已经删除的字符数目达到了不匹配的个数 
// 3. 记忆化搜索
#include <bits/stdc++.h>

using namespace std;
class Solution
{
public:
    vector<string> ans;
    map<string, bool> memo;

    // 首先我们遍历一次字符串，得到我们不匹配的字符数量是多少
    // 包括左右括号
    int mismatched(string s) {
        int l = 0;
        int r = 0;
        int ans = 0;

        for (char c : s) {
            if (c == '(') l++;
            else if (c == ')') {
                if (l > 0) l--;
                else ans++;
            }
        }

        ans += l;
        return ans;
    }

    // 如果当前的字符串已经处理过了，
    // 直接返回
    // 否则的话，进行搜索
    void backtrack(string s, int toRemove) {
        // Terminate Condition
        // 1. If Searched
        // 2. No more toRemove
        if (memo[s]) return;
        else memo[s] = true;

        // 如果需要删除的是0个
        // 判断当前的字符串是否valid
        // 如果是  就返回true
        if (toRemove == 0)
        {
            int n = mismatched(s);
            if (n == 0) ans.push_back(s);
            return;
        }
        // 删除当前的字符，然后继续
        for (int i = 0; i < s.length(); i++)
        {
            string left = s.substr(0, i);
            string right = s.substr(i + 1);
            backtrack(left + right, toRemove - 1);
        }
    }

    vector<string> removeInvalidParentheses(string s)
    {
        // 首先记录我们需要删除的字符数量
        int toRemove = mismatched(s);
        // 开始搜索
        backtrack(s, toRemove);
        return ans;
    }
};
