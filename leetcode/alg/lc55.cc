// leetcode 55
// Jump Game

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // 考虑cur为当前可达的位置
    bool canJump(vector<int>& nums) {
        int cur = nums[0] + 0;
        
        for(int i=0; i<nums.size(); i++) {
            // 如果当前的i在可达范围内
            if (cur >= i) cur = max(cur, nums[i] + i);
            // 如果可达范围内已经超过了n-1，那么返回true
            if (cur >= nums.size() - 1) return true;
        }
        return false;
    }
};