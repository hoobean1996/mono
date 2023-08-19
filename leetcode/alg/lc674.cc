// leetcode 674
// Longest Continuous Increasing Subsequence

// 给定一个未排序的数组，返回最长的连续的上升序列

// 必须是连续的
// 考虑至少有两个元素
// 使用双指针 l = 0, r = 1
// 只要是递增的，一直扩展r，
// 这个时候 r - l就是当前的最长长度
// 然后移动l到当前的r，然后移动r到下一个位置
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if (nums.size() == 1) return 1;
        
        int ans = 0;

        // 维护一个区间是满足条件的当前区间
        // 初始化区间长度为1 肯定是满足的
        // 如果下一个元素满足递增的情况，扩大区间
        // 否则的话 l移动到下一个区间的开始位置
        int l = 0;
        int r = 0;
        
        while(r < nums.size()) {
            while(r < nums.size() && r > 0 && nums[r] > nums[r-1]) r++;
            ans = max(ans, r - l + 1);
            l = r + 1;
            r ++;
        }

        return ans;
    }
};