// leetcode 540
// Single Element in a Sorted Array

// 给定一个排序数组
// 每个元素都出现过两次
// 但是有一个唯一的元素仅出现过一次
// 找出这个元素

// 如果是不是有序的数组，那么我们就直接用xor操作即可
// 但是既然是有序数组，那么我们肯定是需要考虑特点的
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int r = n - 1;


        while (l <= r) {
            int mid = l + (r - l) / 2;
            // 如果当前的位置是偶数，那么检查该性质是否满足
            // 考虑没有任何单个元素的时候
            // 11 22 33 
            // 偶数位置的应该是两个相同的数的第一个
            // 奇数位置的应该是两个相同的数的第二个
            // 但是如果插入了一个单个元素，这个性质就会被翻过来
            if (mid % 2 == 0) {
                if (mid + 1 < n && nums[mid] == nums[mid + 1]) l = mid + 1;
                else r = mid - 1;
            }
            // 如果当前的位置是奇数,
            else {
                if (mid - 1 >= 0 && nums[mid] == nums[mid - 1]) l = mid + 1;
                else r = mid - 1;
            }
        }

        // l 是满足该性质的
        return nums[l];
    }
};