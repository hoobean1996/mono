// leetcode 230
// Kth smallest Element in a BST

// 1. 直接中序遍历 O(n)
// 2. 非递归遍历 O(H + k)

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> sk;
        
        while(true) {
            while(root) {
                sk.push(root);
                root = root->left;
            }
            root = sk.top(); sk.pop();
            if (--k == 0) {
                return root->val;
            }
            root = root->right;
        }
        
        return -1;
    }
};