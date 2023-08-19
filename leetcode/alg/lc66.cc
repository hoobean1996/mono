// leetcode 66 
// Plus One

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int c = 0;
        for(int i=digits.size()-1; i>=0; i--) {
            int sum = digits[i] + c + (i == digits.size() - 1 ? 1 : 0);
            digits[i] = sum % 10;
            c = sum / 10;
        }
        
        if (c > 0) {
            digits.insert(digits.begin(), c);
        }
        
        return digits;
    }
};