// leetcode 283
// Move Zeros
// 希望把0的元素都移动到后面去
// 相当于把非0的元素都移动到前面去
// 定义i代表上一个非0元素的位置，初始化为-1
// 遍历整个数组，如果遇到非0的元素，将它放置到 ++i的位置即可
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();

        int i = -1;
        int j = 0;

        while(j < n) {
            if (nums[j] != 0) nums[++i] = nums[j];
            j++;
        }

        while(i + 1 < n) nums[++i] = 0;
    }
};