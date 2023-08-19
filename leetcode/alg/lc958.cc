// leetcode 958
// Check Completeness of Binary Tree

// 给定一棵二叉树，我们想知道它是否为完全二叉树
// 基本思路是利用BFS来遍历所有的点，如果是完全二叉树的话，那么遍历出来的节点编号是连续的。
// 把根节点放入到队列中 编号为1，同时维护一个当前expect值，初始化为1
// 每从队列中取出一个元素，首先对比该节点的label是否和expect相同，如果相同就继续
// 不同就返回false
// 对于每个取出来的元素，如果它有孩子节点，我们就放入编号为 2*label, 2*label + 1到队列即可， 同时expect ++;
#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(): val(0), left(left), right(right) {}
    TreeNode(int x): val(x), left(left), right(right) {}
    TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right) {}  
};

class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        if (!root) return false;
        
        queue<pair<TreeNode*, int>> q;
        q.push({root, 1});
        
        // 利用last记录上一次的ID，这样当从队列中取出一个ID的时候，就能判断是否连续
        int expect = 1;
        
        while(!q.empty()) {
            auto [u, id] = q.front(); q.pop();
            if (id != expect) return false;
            expect ++;
            if (u->left) q.push({u->left, 2 * id});
            if (u->right) q.push({u->right, 2 * id + 1});
        }
        
        return true;
    }
};