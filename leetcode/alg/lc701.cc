// leetcode 701
// Insert into a Binary Search Tree

// 给定一棵二叉搜索树的根节点，我们想在这颗二叉树里面插入一个节点
// 利用BST的性质，左子树更小，右子树更大
// 不断的和当前的root节点做比较，如果右子树存在，就移动到右子树，
// 如果左子树，就移动到左子树
// 最后在一个没有左儿子/右儿子的位置插入即可
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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        // 如果这棵树是空树的话，我们就创建一个根节点并返回
        if (!root) {
            root = new TreeNode(val);
            return root;
        }
        
        TreeNode* ans = root;
        
        // 通过比较插入的值和当前节点的大小
        while(root) {
            // 如果需要插入的值比当前的节点大的话
            if (val > root->val) {
                // 如果没有右子树的话，就插入到这里
                // 否则的话，就继续移动到右子树
                if (root->right == nullptr) {
                    root->right = new TreeNode(val);
                    break;
                }
                else root = root->right;
            }
            // 如果需要插入的值比当前的节点小的话
            // 如果没有左子树的话，就插入到这里
            // 否则的话，就继续移动到左子树
            else if (val < root->val) {
                if (root->left == nullptr) {
                    root->left = new TreeNode(val);
                    break;
                }
                else root = root->left;
            }
        }
        
        return ans;
    }
};