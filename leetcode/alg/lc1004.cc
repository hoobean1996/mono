// leetcode 1004
// Max Consecutive Ones III

// 给定一个01数组，和一个整数k
// 寻求最大的连续的1的区间，在这个区间内，我们可以最多反转k个0->1

// 题目要求是可以flip最多k个0，其实就是利用双指针维护一个区间，该区间的0的数量不超过k，
// 如果超过k，就移动l指针缩小区间
// 维护区间[l, r] 该区间的0的数量不超过k即可
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0;
        int zeros = 0;
        int ans = 0;
        
        for(int r=0; r<nums.size(); r++) {
            if (nums[r] == 0) zeros ++;
            
            // 如果超过k个0的话，尝试移动l来使得该区间满足条件
            while(zeros > k) {
                if (nums[l] == 0) zeros --;
                l ++;
            }
            
            ans = max(ans, r - l + 1);
        }
        
        return ans;
    }
};