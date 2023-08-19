// leetcode 510
// Inorder Successor in BST II

// 给定一棵二叉搜索树，和一个节点，我们需要找到在这颗二叉搜索树中后继节点是什么
// 首先考虑的是如果这个节点有右子树，那么我们就找到右子树的最左节点就好
// 如果没有右子树，它的某个parent就是它的后继
#include <bits/stdc++.h>

using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node* parent;

    Node() : val(0), left(nullptr), right(nullptr), parent(nullptr) {}
    Node(int x) : val(x), left(nullptr), right(nullptr), parent(nullptr) {}
    Node(int x, Node* left, Node* right, Node* parent) : val(x), left(left), right(right), parent(parent) {}
};

class Solution {
public:

    Node* inorderSuccessor(Node* node) {
        // 如果该节点有直接右子树，那么直接返回右子树的最左节点
        if (node->right) {
            node = node->right;
            while (node->left) node = node->left;
            return node;
        }
        // 如果没有直接右子树的话
        // 如果该节点是其parant节点的右子树，那么我们就应该递归找上去
        // 停止条件 
        //   要么就是没有parent节点（它本身是最大的）
        //   要么就是是parent的左儿子，（那么此时的parent就是它的后继）
        while (node->parent && node == node->parent->right) node = node->parent;
        return node->parent;
    }
};