// leetcode 250
// Count Univalue Subtrees
// 给定一个二叉树，我们想知道有多少个uni-value的子树
// 一个uni-value的子树是这颗子树的所有节点都是相同的值
// 考虑类似后续遍历的模式即可，先递归的得到左右两个子树的情况，然后merge
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int count = 0;
    
    bool is_uni(TreeNode* node) {
        if (!(node->left) && !(node->right)) {
            count ++;
            return true;
        }
        
        bool is_unival = true;
        
        if(node->left) {
            is_unival = is_uni(node->left) && is_unival && node->val == node->left->val;
        }
        
        if(node->right) {
            is_unival = is_uni(node->right) && is_unival && node->val == node->right->val;
        }
        
        if (!is_unival) return false;
        count ++;
        return true;
    }
    
    int countUnivalSubtrees(TreeNode* root) {
        if (!root) return 0;
        is_uni(root);
        return count;
    }
};