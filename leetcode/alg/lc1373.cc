// leetcode 1373
// Maximum Sum BST in Binary Tree

// 给定一棵二叉树，在它的所有子树中，我们想要找到最大的那颗二叉搜索树
#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() {}
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right) {};
};

// 首先我们定义一个NodeValue用来代表当前节点的为子树的信息
// 整体来说还是采用后序遍历的模式
// 我们首先考虑左右两颗子树的信息
// 判断是否当前节点能否构成更大二叉树
class Solution {
public:
    int ans = 0;
    
    class NodeValue {
    public:
        int maxNode, minNode, sum;
        
        NodeValue(int minNode, int maxNode, int sum) {
            this->minNode = minNode;
            this->maxNode = maxNode;
            this->sum = sum;
        }
    };
    
    NodeValue helper(TreeNode* root) {
        // 注意到这个空节点的初始化是
        // 最小值 = INT_MAX
        // 最大值 = INT_MIN
        // 考虑一个空节点作为左子树返回的话， l->max < node->val
        // 所以最大值应该是MIN, 
        // 考虑一个空节点作为右子树返回的话，r->min > node->val
        // 所以最小值是MAX
        if (!root) return NodeValue(INT_MAX, INT_MIN, 0);

        // 分别考虑左右子树，然后判断是否满足BST的条件
        // left.max < root->val and right.min > root->val
        // 这种情况下，我们需要聚合信息并向上返回
        // 由于有空节点的情况，所以是
        // min(root->val, left.min)
        // max(root->val, right.max)
        // left.size + right.size + 1 + 1
        auto left = helper(root->left);
        auto right = helper(root->right);
        if (left.maxNode < root->val && root->val < right.minNode) {
            NodeValue v = NodeValue(
                min(root->val, left.minNode),
                max(root->val, right.maxNode),
                left.sum + right.sum + root->val);
            ans = max(ans, v.sum);
            return v;
        }
        
        NodeValue v = NodeValue(INT_MIN, INT_MAX, root->val);
        return v;
    }
    
    int maxSumBST(TreeNode* root) {
        helper(root);
        return ans;
    }
};