// leetcode 260
// Single Number II

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long bitmask = 0;
        for(int n: nums) bitmask ^= n;
        
        long long diff = bitmask & (-bitmask);
        
        int x = 0;
        for(int n: nums) if ((n&diff) != 0) x ^= n;
        
        return {x, (int)bitmask^x};
    }
};