// leetcode 9
// Palindrome Number 

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        
        int y = x;
        long long val = 0;
        
        while(y > 0) {
            val = val * 10 + y % 10;
            y /= 10;
        }
        
        return val == x;
    }
};