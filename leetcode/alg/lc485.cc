// leetcode 485
// Max Consecutive Ones

// 最大连续的一，这道题就是用滑动窗口就能解决
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0;
        
        int count = 0;
        for(int i=0; i<nums.size(); i++) {
            if (nums[i] == 1) count ++;
            else count = 0;
            ans = max(ans, count);
        }
        
        return ans;
    }
};