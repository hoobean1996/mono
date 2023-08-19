// leetcode 307
// Range Sum Query - Mutable
// 给定一个数组，有以下queries
//  - Update the value of elements
//  - Calculate the sum in range [l, r]
// 对于静态的RMQ问题，可以利用一维前缀和/二维前缀和求解
// 对于动态的RMQ问题，可以利用Segment Tree求解

#include <bits/stdc++.h>

using namespace std;

class NumArray {
public:
    // 线段树实现
    vector<int> tree;
    int n;
    NumArray(vector<int>& nums) {
        if (nums.size() > 0) {
            n = nums.size();
            // 利用以后的数组构造线段树，需要用2倍的空间
            tree = vector<int>(n * 2);
            buildTree(nums);
        }
    }
    void buildTree(vector<int>& nums) {
        // 原数组会作为叶子节点放置到后n位
        for (int i = n, j = 0; i < 2 * n; i++, j++) tree[i] = nums[j];
        // 前n个位置可以倒序构造，
        for (int i = n - 1; i > 0; i--) tree[i] = tree[i * 2] + tree[i * 2 + 1];
    }
    // update的时候
    // 首先找到叶子节点
    void update(int pos, int val) {
        pos += n;
        tree[pos] = val;
        while (pos > 0) {
            int l = pos;
            int r = pos;

            // 判断该节点是左儿子还是右儿子
            if (pos % 2 == 0) r = pos + 1;
            else l = pos - 1;

            // 更新父节点 
            tree[pos / 2] = tree[l] + tree[r];

            // 递归更新上去
            pos /= 2;
        }
    }

    int sumRange(int left, int right) {
        left += n;
        right += n;
        int sum = 0;

        while (left <= right) {
            if ((left % 2) == 1) sum += tree[left++];
            if ((right % 2) == 0) sum += tree[right--];
            left /= 2;
            right /= 2;
        }

        return sum;
    }
};
