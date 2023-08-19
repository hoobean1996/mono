// leetcode 108
// Convert Sorted Array to Binary Search Tree
// 把一个有序数组转换为高度平衡的二叉搜索树

#include <bits/stdc++.h>

using namespace std;

// 基本的思想是选择中间的值作为root元素

class Solution {
public:
    TreeNode* build(vector<int>& nums, int l, int r) {
        if (l > r) return nullptr;
        
        int p = (l + r) / 2;
        
        TreeNode* root = new TreeNode(nums[p]);
        root->left = build(nums, l, p-1);
        root->right = build(nums, p+1, r);
        return root;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return build(nums, 0, nums.size() - 1);
    }
};