// leetcode 246
// Strobogrammatic Number 

// 中心对称数字
// 中心对称数字是指一个数字旋转180度以后还和原来的数字看起来一样
// 比如我们把69旋转180度，还是69
// 满足旋转以后还是相同的 就是中心对称数字

// 我们可以利用双指针分别指向首尾
// 然后判断
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isStrobogrammatic(string num) {
        unordered_map<int, int> m = {
            {0, 0},
            {1, 1},
            {6, 9},
            {8, 8},
            {9, 6}
        };

        int n = num.length();
        int l = 0;
        int r = n - 1;

        while(l <= r) {
            char left = num[l];
            char right = num[r];

            // 如果当前的数字不在中心对称表里面
            // 或者是把左边的数字旋转以后 不等于右边的数字，都是失败的
            if (m.count(left - '0') == 0 || (m[left - '0'] != right - '0')) return false;
            l ++;
            r --;
        }

        return true;
    }
};