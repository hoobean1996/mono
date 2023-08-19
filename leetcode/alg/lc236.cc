// leetcode 236
// 二叉树的最小公共祖先
#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 考虑一颗二叉树，任意节点p，q
// 那么p，q的最小公共祖先有三种情况
// 1. p,q，lca都在左子树，
// 2. p,q, lca都在右子树
// 3. 如果既不在左子树，又不在右子树，那么当前的root就是lca

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return nullptr;

        if (root == p || root == q) return root;
        
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        
        if (left == nullptr && right == nullptr) return nullptr;
        
        if (left && right) return root;
        else if (left) return left;
        else return right;
    }
};

// 给定一棵树，查找两个节点(u,v)的最小公共祖先，lca(u, v)
// 常用性质:
// lca(u) = u
// 如果u是v的祖先，当且仅当 lca(u,v) = u
// u,v的最小公共祖先一定在u->v的最短路上
// d(u, v) = h(u) + h(v) - 2h(lca(u,v))

// 通过dfs得到欧拉序，可以把LCA问题转换为RMQ问题
// 1. 对一棵树进行DFS，每到达一个节点就记录其编号，可以得到一个2n-1的序列

// lca(u, v) = rmq(first[u], first[v])