// leetcode 50
// Pow(x, n)

// 快速幂
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    double myPow(double x, int nn) {
        double ans = 1;
        int sign = nn > 0 ? 1 : -1;
        int n = abs(nn);
        
        while(n > 0) {
            if (n & 1) ans = ans * x;
            x = x * x;
            n >>= 1;
        }
        
        if (sign == -1) return 1 / ans;
        
        return ans;
    }
};