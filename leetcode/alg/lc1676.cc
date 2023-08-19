// leetcode 1676
// Lowest Common Ancestor of a Binary Tree IV

// 给定一棵二叉树，和一组节点
// 我们希望找到这组节点的最小公共祖先
// 我们利用一个Set存放所有的节点
// 然后后序遍历这棵树
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
    unordered_set<TreeNode*> s;
    // lca返回以当前node为root的子树的哪个节点是某个节点p的祖先
    // 整体是先序遍历的模式
    TreeNode* lca(TreeNode* node) {
        // 如果当前节点是空，那么肯定不是
        if (!node) return nullptr;
        // 如果该节点 == 某个节点，那么这个节点肯定是它自己的祖先
        if (s.count(node)) return node;

        // 如果该节点不是，我们才需要考虑它的左右子树
        TreeNode* l = lca(node->left);
        TreeNode* r = lca(node->right);
        
        // 如果左右子树都没有祖先，那么对于该节点来说，也不是
        if (l == nullptr && r == nullptr) return nullptr;
        // 如果两个节点都是的话，证明左右子树至少各是一个节点的祖先，那么该节点就是最小公共祖先，返回自己
        if (l && r) return node;
        // 如果某个节点是的话，那么就返回某个节点即可
        else if (l) return l;
        else return r;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, vector<TreeNode*> &nodes) {
        s.insert(begin(nodes), end(nodes));
        return lca(root);
    }
};