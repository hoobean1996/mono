// leetcode 154
// Find Minimum in Rotated Sorted Array II

// 给定一个旋转过k次的有序数组 (注意该数组可能出现重复元素)
// 找到其中的最小值
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        
        while(l < r) {
            int mid = l + (r - l) / 2;
            // 如果nums[mid]小于nums[r]
            // 证明
            if (nums[mid] < nums[r]) r = mid;
            else if (nums[mid] > nums[r]) l = mid + 1;
            // 相比不可重复的情况 多了一个r--
            else r --;
        }
        
        return nums[l];
    }
};