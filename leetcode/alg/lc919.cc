// leetcode 919
// Complete Binary Tree Inserter
// 完全二叉树的插入器
// 对于一个完全二叉树，插入第一个新节点的时候，一定是从第一个有null子节点的节点开始
// 所以我们利用一个deque来维护待插入的candidates
// 在插入的时候 从candidates里面取出一个 头节点并赋值为他的某个儿子，
// 如果是头节点的左儿子的话，证明还能插入一个值，不需要弹出
// 如果是头节点的右儿子的话，证明不能在插入任何值了，需要弹出
#include <bits/stdc++.h>

using namespace std;
class CBTInserter {
public:
    TreeNode* root;
    // dq用来存放所以可以进行插入操作的节点，（某个儿子为null） 
    deque<TreeNode*> dq;
    
    // 给定一棵二叉树来初始化这个完全二叉树的Inseter
    CBTInserter(TreeNode* r) {
        root = r;
        queue<TreeNode*> q;
        q.push(root);
        
        // 首先进行BFS
        // 如果当前的节点至少有一个儿子为空的话，那么就是某次节点插入的candidate。
        // 初始化完成以后，candidates都在dq里面了

        while(!q.empty()) {
            TreeNode* node = q.front(); q.pop();
            
            if (node->left == nullptr || node->right == nullptr) dq.push_back(node);
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
    }
    
    // 插入的时候，首先拿到对头节点
    // 然后把当前的新节点放入到dq队尾，因为它的儿子一定为空
    int insert(int val) {
        TreeNode* newNode = new TreeNode(val);
        dq.push_back(newNode);

        TreeNode* node = dq.front();
        
        // 如果对头节点的左儿子为空的话，
        // 设置为该节点的左儿子
        if (node->left == nullptr) {
            node->left = newNode;
        }
        // 如果对头节点的右儿子为空的话
        // 设置为该节点的右儿子
        // 同时弹出队友节点，（因为如果它的右儿子不为空了的话
        // 意味着它的两个儿子都有了
        // 所以不可能是candidate了
        else {
            node->right = newNode;
            dq.pop_front();
        }
        
        return node->val;
    }
    
    TreeNode* get_root() {
        return root;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */