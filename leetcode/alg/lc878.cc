// leetcode 878
// Nth Magical Number 
// 给定两个数a，b，我们想求第n个magical number
// 一个magical number是可以被a 或者 b整除的数
// 利用数论 + 二分搜索来解决

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }
    
    int nthMagicalNumber(int n, int a, int b) {
        int MOD = 1e9 + 7;
        // a 和 b的最小公倍数
        int L = a / gcd(a, b) * b;
        
        long l = 0;
        long r = (long) n * min(a, b);
        while(l < r) {
            long mid = l + (r - l) / 2;
            // 没有足够的magic number
            if (mid / a + mid / b  - mid / L < n) l = mid + 1;
            else r = mid;
        }
        
        return (int)(l % MOD);
    }
};