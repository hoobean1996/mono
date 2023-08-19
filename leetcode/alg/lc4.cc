// leet code 
// Median of two sorted array
// 给定两个有序数组，如果我们把两个数组合并成一个有序数组以后，可以得到一个中位数
// 我们想知道这个中位数是多少
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int m = nums1.size();
    int n = nums2.size();
    // 确保第二个数组更长
    if (m > n) return findMedianSortedArrays(nums2, nums1);
    // 处理只有一个数组的情况
    if (m == 0) return (nums2[(n-1)/2] + nums2[n/2] )/ 2.0;
    // 考虑中位数的意义，
    // 假设A[0], A[1], ..., A[i-1] 和 A[i], A[i+1], ..., A[m-1] 被划分为两侧
    //    B[0], B[1], ..., B[j-1] 和 B[j], B[j+1], ..., B[n-1]
    // 我们需要达到的的条件是
    // 1. len(Left) == len(Right)
    // 2. max(left) <= min(Right)
    //  -> A[i-1] <= B[j] && B[j-1] <= A[i]
    int l = 0;
    int r = m;
    int half = (m + n + 1) / 2;

    int maxOfLeft;
    int minOfRight;

    while(l <= r) {
        int i = l + (r - l) / 2;
        int j = half - i;
        
        // 由于i+j = half
        // case 1: i过于小了，导致了最大值条件不满足
        // 由于nums1[i] + i in [0, m] 所以需要加上条件 i < m
        if (i < m && nums2[j-1] > nums1[i]) l = i + 1;
        // case 2: i过于大了，导致最大值条件不满足
        // 由于nums[i-1] + i in [0, m] 所以需要加上条件 i > 0
        else if (i > 0 && nums1[i-1] > nums2[j]) r = i - 1;

        // case 3
        else {
            // 考虑左边某个数组为空的情况
            // A数组的划分，左半边为空
            if (i == 0) maxOfLeft = nums2[j-1];
            // B数组的划分，左半边为空
            else if (j == 0) maxOfLeft = nums1[i-1];
            else maxOfLeft = max(nums1[i-1], nums2[j-1]);

            // 如果只有奇数个元素
            if ((m+n) % 2 == 1) return maxOfLeft;

            // 考虑右边某个数组为空的情况
            if (i == m) minOfRight = nums2[j];
            else if (j == n) minOfRight = nums1[i];
            else minOfRight = min(nums1[i], nums2[j]);

            return (maxOfLeft + minOfRight) / 2.0;        
        }
    }

    return -1;
    }
};