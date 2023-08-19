// leetcode 1249
// Minimum Remove to Make valid Parentheses

// 给定一个括号序列，可能包含左括号和右括号
// 注意到当前的括号序列可能是不合法的，也就是说左右括号不匹配
// 我们希望删除最少的符号来让剩下的括号序列是合法的（左右括号匹配）
// 遍历两次，第一次遍历的时候，我们把多余的 ) 删去，得到一个字符串，这个字符串中的 ( >= )的数量
// 在处理完第一次以后，我们得到的字符串只有多余的(，所以我们只需要考虑在遇到(的时候，判断是否需要保留即可

// 1. 首先从左到右遍历一次，删除所有的不合法的 )
// 2. 通过删除所有的)以后，我们的字符串只可能多一些(，
// 所以我们再次遍历第一次处理的结果，在删除多余的(
// 感觉这道题和leetcode 32, 最长有效括号是可以转换的
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string minRemoveToMakeValid(string s)
    {
        string ans;

        // l 代表所有的左括号的数量
        int l = 0;
        // notMatched 代表还未匹配的左括号数量
        int notMatched = 0;

        // 扫描字符串，遇到左括号的话
        // l,notMatched都需要自增
        // 如果遇到右括号，如果notMatched == 0 意味着，右括号过多了
        // 直接跳过即可
        // 其他情况都需要把字符保留
        // 第一遍历以后，可以确保左括号的数量是 >= 右括号的
        for(const char c: s) {
          if (c == '(') l ++, notMatched++;
          else if (c == ')') {
            if (notMatched == 0) continue;
            notMatched --;
          }
          ans += c;
        }
        
        // 第二次遍历，我们通过 l - notMatched知道正确的数量是多少
        // 所以在遍历字符串的时候，如果遇到左括号 就判断是否足量了，
        // 第二次遍历可以确保 l == r
        string result;
        int matched = l - notMatched;

        for (int i = 0; i < ans.length(); i++)
        {
            char c = ans[i];
            if (c == '(')
            {
                matched--;
                if (matched < 0) continue;
            }
            result += c;
        }

        return result;
    }
};