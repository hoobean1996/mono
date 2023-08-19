// leetcode 334
// Increasing Triplet Subsequence
// 给定一个数组，我们想知道是否存在一个三元组 (i, j, k) 满足
// i < j < k, and nums[i] < nums[j] < nums[k]
// 我们把初始化两个变量为最大值
// f1 < f2 
// x 
// 如果x <= f1 -> f1 = x
// 如果x <= f2 -> f2 = x 
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int f1 = INT_MAX;
        int f2 = INT_MAX;

        for(const int x: nums) {
            if (x <= f1) f1 = x;
            else if (x <= f2) f2 = x;
            else return true;
        }

        return false;
    }
};