// leetcode 173
// Binary Search Tree Iterator

// 希望实现一个二叉搜索树的迭代器
// 我们采用的方案有两种
// 1. 先采用中序遍历，然后维护一个index，这样的时间复杂度是O(n), 空间复杂度O(n)
// 2. 采用非递归的遍历模式，我们首先把root节点
// 把当前root节点和所有的左子节点放入栈中
// 在弹出的时候，如果有右子树的儿子，重复第一个操作
#include <bits/stdc++.h>

using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() {}

    TreeNode(int val) : val(val) {}
};

class BSTIterator {
public:
    stack<TreeNode*> sk;
    
    // 在构造的时候把root节点和所有的左儿子放入进去
    BSTIterator(TreeNode* root) {
        while(root) {
            sk.push(root);
            root = root->left;
        }
    }
    
    int next() {
        // 弹出的时候，
        // 如果有右子树的话，也是把右子树的根节点
        // 和右子树的左儿子们放到栈中
        TreeNode* top = sk.top(); sk.pop();
        
        TreeNode* u = top->right;
        while(u) {
            sk.push(u);
            u = u->left;
        }
        
        return top->val;
    }
    
    bool hasNext() {
        return !sk.empty();
    }
};
