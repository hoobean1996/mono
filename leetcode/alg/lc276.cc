// leetcode 276
// Paint Fence
// 粉刷栅栏

// 有一个长度为n的栅栏，我们有k种颜色可以选择
// 不能超过三个栅栏有相同的颜色
#include <bits/stdc++.h>

using namespace std;

// 定义dp[i]是前i个栅栏的方案
// dp[1] = k
// dp[2] = k*k
// 考虑第i个栅栏之前的两种颜色，
// 如果是A A -> k-1种选择
// A B -> k种选择
class Solution {
public:
    int numWays(int n, int k) {
        if (n == 1) return k;
        if (n == 2) return k * k;
        
        int s = k;
        int s2 = k * k;

       
        
        for(int i=3; i<=n; i++) {
            int cur = (k - 1) * (s + s2);
            s = s2;
            s2 = cur;
        }
        
        return s2;
    }
};