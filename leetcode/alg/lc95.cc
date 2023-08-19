// leetcode 95
// Unique Binary Search Tree ii
// 需要求解具体的二叉树形态
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> build(int l, int r) {
        if (l > r) return {nullptr};

        vector<TreeNode*> subtrees;

        for(int i=l; i<=r; i++) {
            auto leftSubtrees = build(l, i-1);
            auto rightSubtrees = build(i+1, r);

            for(auto leftTree: leftSubtrees) {
                for(auto rightTree: rightSubtrees) {
                    TreeNode* root = new TreeNode(i, leftTree, rightTree);

                    subtrees.push_back(root);
                }
            }
        }

        return subtrees;
    }

    vector<TreeNode*> generateTrees(int n) {
        return build(1, n);
    }
};