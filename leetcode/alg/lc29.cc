// leetcode 29
// Divide two numbers

// 请用减法运算实现除法 n / k
// 如果每次减去 k的话，效率太低
// 假设 n / k = ans
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // const int INT_MIN = -2147483648;
    // const int INT_MAX = 2147483647;
    const int HALF_INT_MIN = -1073741824;
    
    int divide(int dividend, int divisor) {
        // 首先需要考虑的溢出的情况
        // INT_NIN / -1 = INT_MAX
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;

        // 考虑两个数是否均为负数
        int negatives = 2;
        if (dividend > 0) {
            negatives --;
            dividend = - dividend;
        }

        if (divisor > 0) {
            negatives --;
            divisor = -divisor;
        }

        vector<int> doubles;
        vector<int> twos;

        int two = -1;

        while(divisor >= dividend) {
            doubles.push_back(divisor);
            twos.push_back(two);

            if (divisor < HALF_INT_MIN) break;
            divisor += divisor;
            two += two;
        } 

        int quotient = 0;
        for(int i=doubles.size()-1; i>=0; i--) {
            if (doubles[i] >= dividend) {
                quotient += twos[i];
                dividend -= doubles[i];
            }
        }

        if (negatives != 1) return -quotient;
        return quotient;
    }
};

