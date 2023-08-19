// leetcode 338
// Counting Bits

// 给定一个整数n, 返回一个n+1个长度的数组，然后这个数组恰好是n的二进制表示

// 最暴力的办法就是直接利用循环算出1的个数
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // 定义dp[i]表示数字i中二进制表示1的个数
    // 初始化: dp[0] = 0
    // 转移方程: dp[i] = dp[i >> 1] + (i & 1)
    vector<int> countBits(int n) {
        vector<int> ans(n + 1, 0);

        for(int x=1; x<=n; x++) ans[x] = ans[x & (x - 1)] + 1;

        return ans;
    }   
};