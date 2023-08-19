// leetcode 152
// max product subarray

// 定义fmax[i]为以i元素结尾的乘积最大子数组的乘积
// 定义fmin[i]为以i元素结尾的乘积最小子数组的乘积
// 状态转移方程
// fmax[i] = max(fmax[i-1]*nums[i], fmin[i-1]*nums[i], nums[i]);
// fmin[i] = min(fmax[i-1]*nums[i], fmin[i-1]*nums[i], nums[i]);

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int f_max = nums[0];
        int f_min = nums[0];
        int ans = nums[0];
        
        for(int i=1; i<nums.size(); i++) {
            int mx = f_max;
            int mn = f_min;
            f_max = max(mx * nums[i], max(nums[i] * mn, nums[i]));
            f_min = min(mn * nums[i], min(nums[i] * mx, nums[i]));
            ans = max(f_max, ans);
        }

        return ans;
    }
};