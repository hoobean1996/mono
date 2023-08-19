// leetocde 106
//  Construct Binary Tree from Inorder and Postorder Traversal

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size() == 0) return nullptr;
        
        int root = postorder[postorder.size()-1];
        postorder.pop_back();
        
        vector<int> leftinorder;
        vector<int> rightinorder;
        bool is_left_in_order = true;
        for(int i=0; i<inorder.size(); i++) {
            if (inorder[i] == root) {
                is_left_in_order = false;
                continue;
            }
            
            if (is_left_in_order) leftinorder.push_back(inorder[i]);
            else rightinorder.push_back(inorder[i]);
        }
        
        vector<int> leftpostorder;
        vector<int> rightpostorder;
        for(int i=0; i<postorder.size(); i++) {
            if (leftpostorder.size() < leftinorder.size()) leftpostorder.push_back(postorder[i]);
            else rightpostorder.push_back(postorder[i]);
        }
        
        TreeNode* r = new TreeNode(root, nullptr, nullptr);
        TreeNode* left = buildTree(leftinorder, leftpostorder);
        TreeNode* right = buildTree(rightinorder, rightpostorder);
        r->left = left;
        r->right = right;
        return r;
    }
};