// leetcode 270
// Closest Binary Search Tree Value

// 给定一棵二叉搜索树，和一个给定的值value，希望在在这颗树上找到离
// 这个value最近的节点
// 假设最近的是root的节点
// 我们开始遍历这棵树，如果当前节点的距离更近，我们就更新
// 并根据target和当前节点的大小关系进行移动
#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int closestValue(TreeNode* root, double target) {
        int ans = root->val;
        
        while(root) {
            ans = abs(root->val - target) < abs(ans - target) ? root->val : ans;
            
            root = target < root->val ? root->left : root->right;
        }
        
        return ans;
    }
};