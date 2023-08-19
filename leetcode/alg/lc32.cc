// leetcode 32
// Longest Valid Parentheses

// 给定一串括号串，我们想找到其中最长的有效的括号子串的长度.
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length();
        int res = 0;

        // 定义dp[i]是以下标i为结尾的最长括号长度
        vector<int> dp(n, 0);

        for(int i=0; i<n; i++) {
            // 如果第一个字符是 ) 肯定不行的
            if (i > 0 && s[i] == ')') {
                // xx ()
                // 这种情况，需要考虑dp[i-2]
                if (s[i-1] == '(') {
                    // i - 2 >= 0 保证下标合法
                    int val = i - 2 >= 0 ? dp[i-2] : 0;
                    dp[i] = 2 + val;
                } else {
                    // (()) 
                    // 这种情况
                    int index = i - dp[i-1] - 1;
                    if (index >= 0 && s[index] == '(') {
                        int val = index > 0 ? dp[index-1] : 0;
                        dp[i] = 2 + dp[i-1] + val;
                    }
                }

                res = max(res, dp[i]);
            }
        }

        return res;
    }
};

// The total time complexity O(n)
// The total space complexity O(1)
// 求解最长的有效括号
class Solution {
public:
    int longestValidParentheses(string s) {
        int l = 0;
        int r = 0;
        int maxLength = 0;
        // 从左往右扫描，统计左右括号的数量
        // 如果左右括号匹配的情况，我们就更新最大可能的结果
        // 由于是字串，所以当不满足匹配的时候就可以把l, r清0
        // 第一轮跑完以后我们以)为基准 l>=r
        for(int i=0; i<s.length(); i++) {
            if (s[i] == '(') l++;
            else r ++;
    
            if (l == r) maxLength = max(maxLength, 2*r);
            else if (r >= l) {
                l = 0;
                r = 0;
            }
        }

        // 第二轮跑完以后我们以(为基准 l<=r
        l = 0;
        r = 0;
        for(int i=s.length() - 1; i>=0; i--) {
            if (s[i] == '(') l ++;
            else r ++;

            if (l == r) {
                maxLength = max(maxLength, 2*l);
            }
            else if (l >= r) {
                l = 0;
                r = 0;
            }
        }

        return maxLength;
    }

};


