// leetcode 977
// Squares of a Sorted Array

// 给定一个数组，我们希望把整个数组中的每个元素都平方以后，按顺序排列。
// 基本的方法是直接求解并排序
// 优化的方法是双指针
// 通过两个指针l 和 r分别指向首尾元素
// 每次选择平方较大 并移动即可
#include <bits/stdc++.h>

using namespace std;

vector<int> sortedSquares(vector<int>& nums) {
    int l = 0;
    int r = nums.size() - 1;

    vector<int> ans(nums.size(), 0);
    int k = r;

    while (l <= r) {
        int suml = abs(nums[l] * nums[l]);
        int sumr = abs(nums[r] * nums[r]);
        if (suml >= sumr) {
            ans[k--] = suml;
            l++;
        }
        else {
            ans[k--] = sumr;
            r--;
        }
    }

    return ans;
}