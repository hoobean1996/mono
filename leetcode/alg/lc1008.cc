// leetcode 1008
// Construct Search Tree From Preorder Traversal

// 从前序遍历的数组构建一棵二叉搜索树
// 二叉搜索树的构建还是需要利用[lower, higher]的范围去限制新的节点
// 一定要记住二叉搜索树是需要满足范围条件的
// build(preorder, MIN, MAX) 根节点是没有任何限制的
//  但是在递归调用的时候
//  需要考虑如果当前的val不在该范围内，那么返回nullptr
#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right) {}
};

class Solution {
public:
    // index 用于指向当前处理的节点
    int index = 0;
    
    TreeNode* build(vector<int>& preorder, int mi, int mx) {
        if (index == preorder.size()) return nullptr;
        
        // 注意到val不是preorder的第一个元素
        // 而是当前index指向的元素
        int val = preorder[index];
        
        if (val < mi || val > mx) return nullptr;
        
        TreeNode* root = new TreeNode(val);
        index ++;
        root->left = build(preorder, mi, val);
        root->right = build(preorder, val, mx);
        
        return root;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return build(preorder, INT_MIN, INT_MAX);
    }
};