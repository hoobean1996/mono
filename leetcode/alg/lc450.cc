// leetcode 450
// Delete Node in a BST
// 给定一棵二叉搜索树，我们想要删除一个节点，同时还要维护二叉搜索树的性质
// 这个需要考虑待删除节点的情况
// 1. 如果这个节点没有任何的子节点，那么直接把该节点置为nullptr即可
// 2. 如果这个节点有右子树，那么首先这个节点的值需要更新为右子树的最左节点，同时还需要在右子树中递归删除改最左节点
// 3. 如果这个节点有左子树，那么需要更新为前驱节点

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
    // successor 返回一个节点的后继
    // 右子树的最左节点
    int successor(TreeNode* root) {
        // 当前节点右子树的最左节点
        root = root->right;
        while(root->left) root = root->left;
        return root->val;
    }
    
    // predecessor 返回一个节点的前驱
    // 左子树的最右节点
    int predecessor(TreeNode* root) {
        // 当前节点左子树的最右节点
        root = root->left;
        while(root->right) root = root->right;
        return root->val;
    }
    
    // 考虑deleteNode会在以root为根的子树中删除key，并返回root
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return root;
        // 递归的删除，找到正确的节点
        if (key > root->val) root->right =  deleteNode(root->right, key);
        else if (key < root->val) root->left =  deleteNode(root->left, key);
        else {
            // 需要删除的节点可能有三种情况
            // 1. 没有子节点
            if (root->left == nullptr && root->right == nullptr) root = nullptr;
            // 2. 存在右节点
            // 那么需要把当前root的值改为后继节点的值
            // 然后在右子树中删除那个后继节点
            else if (root->right) {
                root->val = successor(root);
                root->right = deleteNode(root->right, root->val);
            }
            // 3. 存在左节点
            // 那么需要把当前root的值改为前驱节点
            // 然后在左子树中删除那个前驱节点
            else {
                root->val = predecessor(root);
                root->left = deleteNode(root->left, root->val);
            }
        }
        
        return root;
    }
};