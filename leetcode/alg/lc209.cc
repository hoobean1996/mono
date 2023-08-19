// leetcode 209 
// Minimum Size Subarray Sum

// 给定一个数组，只包含正数，我们想找到一个连续的子数组，使得他们的和 >= 给定的target
// 可能满足条件的子数组有很多，我们希望找到最小的那个子数组
// 和其他subarray sum的问题类似，这里是通过sum >= target来移动左指针的
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int ans = 1e9;

        int l = 0;
        int sum = 0;
        
        for(int r=0; r<n; r++) {
            sum += nums[r];
            
            while(sum >= target) {
                ans = min(ans, r - l + 1);
                sum -= nums[l++];
            }
        }
        
        return (ans != 1e9) ? ans : 0;
    }
};