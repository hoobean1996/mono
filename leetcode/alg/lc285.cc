// leetcode 285
// 二叉树搜索树的节点后继

// 利用BST的性质
// 一个节点的后即是它的右子树中的最左节点
// 首先通过二叉搜索树的性质找到第一个大于p的节点
// 然后不断的往左移动
// 和leetcode 510的区别是，那道题是每个节点都有parent的指针
// 而这道题是没有的，但是有root节点，（这样我们就能遍历整棵树
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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode* succ = nullptr;

        // 给定BST寻找某个p节点的后续节点
        // 1. 可能是P的parent节点
        // 2. p的右节点存在的话，右子树的最左节点
        while (root != nullptr) {
            // 如果p在右子树的话，直接移动
            // 如果在左子树的话，先记录当前的root节点，在移动即可
            //   如果移动到左子树以后，没有右儿子的话，那么当前的root就是他的后继
            if (root->val <= p->val) root = root->right;
            else {
                succ = root;
                root = root->left;
            }
        }

        return succ;
    }
};