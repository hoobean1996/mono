// leetcode 437
// Path Sum iii

// 给定一棵二叉树和一个目标值，我们想找到所有可能的路径方案，
// 该路径上的每个节点值的和等于该目标值
// 整体思路可以参考subarray sum equals k的思路
#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int ans = 0;
    unordered_map<int, int> h;
    
    // sum是当前的前缀和
    // k是target
    // 整体是先序遍历
    void preorder(TreeNode* node, int sum, int k) {
        if (!node) return;

        sum += node->val;
        ans += h[sum-k];
        // 在处理完当前节点的左右儿子以后，记得把该sum去除
        h[sum] ++;

        preorder(node->left, sum, k);
        preorder(node->right, sum, k);
        
        h[sum] --;
    }
    
    int pathSum(TreeNode* root, int targetSum) {
        h[0] = 1;
        preorder(root, 0, targetSum);
        return ans;
    }
};