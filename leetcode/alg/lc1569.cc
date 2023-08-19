// leetcode 1569
// Number of Ways to Reorder Array to Get Same BST

// 给定一个数组，我们可以通过不断将其中的元素插入到一棵二叉搜索树上来完成构建
// 我们发现，重排这个数组来重新插入到搜索树的话，有些重排是能得到一样的二叉搜索树
// 请问对于给定的数组，一共有多少种方式可以得到一棵二叉搜索树
#include <bits/stdc++.h>

using namespace std;
// 这道题是动态规划的题
// 注意到第一个节点一定是跟节点
// 定义f[now]是以now为根节点的子树可以形成的方案树
// 不妨设左子树的节点数是l，右子树的节点数是r
// f[now] = f[now->left] * f[now->right] * C(l+r, r)


// 考虑当前的节点
// f[now] = f[now.left] * f[now.right] * C(l+r, r)
class Solution {
public:
    const int mod = (int)(1e9) + 7;
    
    vector<vector<int>> C;
    
    int numOfWays(vector<int>& nums) 
    {
        int n = nums.size();
        C.resize(n, vector<int>(n, 0));
        for (int i = 0; i < n; ++i)
        {
            C[i][0] = 1;
            for (int j = 1; j <= i; ++j)
                C[i][j] = (C[i-1][j] + C[i-1][j-1]) % mod;
        }
        // - 1 是为了排除已经给出的方案
        return f(nums) % mod - 1;
    }
    
    // 递归处理该数组
    int64_t f(vector<int> &nums)
    {
        int n = nums.size();
        // 如果只有一个元素，那么只有一种方案
        if (n <= 1) return 1;
        
        // 分别处理左右子树
        // 把这个数组划分给左右子树
        // nums[0]是当前数的根
        // 所以基于该前提，我们可以划分数组为两个子数组
        vector<int> left, right;
        for (int i = 1; i < n; ++i)
        {
            if (nums[i] > nums[0]) right.emplace_back(nums[i]);
            else left.emplace_back(nums[i]);
        }
        // 分别计算左右子树
        int64_t lval = f(left) % mod, rval = f(right) % mod;
        // 合并
        return ((C[n - 1][left.size()] * lval) % mod * rval) % mod;
    }
};