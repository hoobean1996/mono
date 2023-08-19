// leetcode 1586
// Binary Search Tree Iterator II

// 二叉树的迭代器实现
// 一种办法是基于中序排列变成一个数组，然后在维护一个index指针即可，实现简单
// O(n)的空间复杂度
// 基于非递归遍历二叉树，我们把空间复杂度优化到O(h)
#include <bits/stdc++.h>

using namespace std;

class BSTIterator {
public:

    stack<TreeNode*> sk;
    vector<int> vals;
    int index = -1;

    // 在构造函数中，我们把根节点，以及所有的左子节点放入到栈中
    // vals是用来存放已经处理过的元素，
    // 由于支持prev操作，所以可能一直在几个元素中徘徊
    BSTIterator(TreeNode* root) {
        while(root) {
            sk.push(root);
            root = root->left;
        }
    }
    
    bool hasNext() {
        return !sk.empty() || index < vals.size() - 1;
    }
    
    // 要获取下一个元素的话
    // 首先考虑要考虑的是，是否现有的vals不够用了
    // 如果不够用了，我们就要利用栈中的节点，在取一些新的节点到vals
    int next() {
        index ++;
        if (index == vals.size()) {
            TreeNode* top = sk.top(); sk.pop();
            vals.push_back(top->val);
            
            // 每弹出一个栈顶节点，都需要把该节点的右子树的根节点和所有左子节点放入到栈中
            TreeNode* node = top->right;
            while(node) {
                sk.push(node);
                node = node->left;
            }
        }
        return vals[index];   
    }
    
    bool hasPrev() {
        return index > 0;
    }
    
    int prev() {
        index --;
        return vals[index];
    }
};
