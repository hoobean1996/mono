// leetcode 776
// Split BST

// 给定一棵二叉搜索树，和一个整数k，我们希望把这颗二叉搜索树划分成两颗树
// 一棵树的所有节点是 <= k
// 另外一棵树的所有节点是 > k
#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    // 假设splitBST会返回两颗子树
    // 一棵是大于该节点的，另外一棵是小于等于该节点的
    // {<=, >}
    vector<TreeNode*> splitBST(TreeNode* root, int target) {
        // 递归终止条件
        // 如果当前节点为空
        // 那么结果是{nullptr, nullptr}
        if (!root) return {nullptr, nullptr};

        // 如果当前的节点 <= target，那么左子树中的所有节点都是 <= target的，不必继续处理
        // 所以把右子树处理为 next= {<=, >}
        // 那么对于当前的节点来说
        // root->right = next[0] 
        // 这样就能把右子树中所有的可用的节点拿过来了
        // 然后把ans[0] 用整颗树替换即可
        else if (root->val <= target) {
            vector<TreeNode*> ans = splitBST(root->right, target);
            root->right = ans[0];
            ans[0] = root;
            return ans;
        }
        // 如果当前的节点 > target， 那么右子树肯定是 > target的，不必继续处理
        // 所以把左子树处理为 next {<=, >}
        // 那么对于当前的节点来说
        // root->left = ans[1]
        // 这样就能把右子树所有的可用的节点拿过来
        else {
            vector<TreeNode*> ans = splitBST(root->left, target);
            root->left = ans[1];
            ans[1] = root;
            return ans;
        }
    }
};