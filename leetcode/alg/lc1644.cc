// leetcode 1644
// Lowest Common Ancestor of a Binary Tree II

// 给定一棵二叉树，此外在给出两个节点p，q
// 我们希望找到这两个节点的最小公共祖先
// 注意到p和q可能不在树上，这个情况下返回nullptr

#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right) {}
};

// 采用后序遍历二叉树，在处理当前节点的时候，判断它是否为p或者q
// 相比普通的lca，p，q可以不这棵树上，所以需要用两个flag标记
class Solution {
public:
    bool pFound = false;
    bool qFound = false;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans = lca(root, p, q);
        if(pFound && qFound) return ans;
        else return NULL;
    }
    
    // 由于p和q可能不在该树上，所以我们是需要后续遍历的
    // 和基本lca的区别在这里
    // 后序遍历可以保证我们一定遍历了所有的节点，同时会把p q找到的标记赋值为true
    TreeNode* lca(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return nullptr;

        TreeNode* l = lca(root->left, p,  q);
        TreeNode* r = lca(root->right, p, q);

        if(root == p || root == q) {
            if(p == root) pFound = true;
            if(q == root) qFound = true;
            return root;
        }

        if(l == nullptr && r == nullptr) return nullptr;

        if (l && r) return root;
        else if (l) return l;
        else return r;
    }
};