// leetcode 233
// Number of Digit one

// 给定一个整数n
// 我们需要找到所有<=n的数中，所有的数位上1出现的次数
class Solution {
public:
    int countDigitOne(int n) {
        int count = 0;

        for(long long i=1; i<=n ;i *= 10) {

            long long divider = i * 10;
            
            count += (n / divider) * i + min(max(n % divider - i + 1, 0LL), i);
        }
        return count;
    }
};