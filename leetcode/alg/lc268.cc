// leetcode 268
// Missing Number 

// 巧妙的利用index是[0..n-1]，对应的值是[0..n]
// 所以除了缺失的那个数意外，其他的数都出现了两次，直接xor就能找到他
// 如果缺失的就是n的话，在循环中全部会把 0 .. n-1抵消
// 如果缺失的不是n的话，在某个时刻n会被抵消
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int missing = n;

        for(int i=0; i<n; i++) {
            missing ^= i;
            missing ^= nums[i];
        }
        
        return missing;
    }
};