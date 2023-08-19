// leetcode 530
// Minimum Absolute Difference in BST

// 求一棵二叉搜索树的最小的差值
// 由于中序遍历二叉搜索树是有序的，所以最小值肯定是相邻的两个节点之间的
// 所以维护一个prev指针即可
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
    TreeNode* prev;
    int ans = 1e9;
    
    // 直接中序遍历，在处理完当前节点之后，在把prev更新为当前节点
    void dfs(TreeNode* root) {
        if (!root) return;
        dfs(root->left);
        
        if (prev) ans = min(ans, abs(root->val - prev->val));
        prev = root;
        
        dfs(root->right);
    }
    
    int getMinimumDifference(TreeNode* root) {
        dfs(root);
        
        return ans;
    }
};