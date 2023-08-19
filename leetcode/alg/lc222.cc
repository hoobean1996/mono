// leetcode 222
// Count Complete Tree Nodes

// 给定一棵完全二叉树，请统计它的节点个数
// 1. 最简单的方法是遍历二叉树并计数即可
// 2. 考虑如何利用完全二叉树的性质
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // 求出二叉树的高度
    int depth(TreeNode* node) {
        int d = 0;
        while(node->left != nullptr) {
            d ++;
            node = node->left;
        }
        return d;
    }
    
    bool exist(int idx, int d, TreeNode* node) {
        int l = 0;
        int r = pow(2, d) - 1;

        for(int i=0; i<d; i++) {
            int mid = l + (r - l) / 2;
            if (idx <= mid) {
                node = node->left;
                r = mid;
            }
            else {
                node = node->right;
                l = mid + 1;
            }
        }
        
        return node != nullptr;
    }
    
    int countNodes(TreeNode* root) {
       if (!root) return 0;
        
        // 如果树高为1的话，则返回1
        int d = depth(root);
        if (d == 0) return 1;
        
        // 二分法
        int l = 1;
        int r = pow(2, d) - 1;


        while(l <= r) {
            int mid = l + (r - l) / 2;
            if (exist(mid, d, root)) l = mid + 1;
            else r = mid - 1;
        }
        
        return pow(2, d) - 1 + l;
    }
};