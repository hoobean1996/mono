// leetcode 129
// Sum Root to Leaf Numbers

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int ans = 0;
    
    void dfs(TreeNode* node, string number) {
        if (!node) return;
            
        number += to_string(node->val);
        
        if (node->left == nullptr && node->right == nullptr) {
            ans += stoi(number);
            return;
        }
        
        dfs(node->left, number);
        dfs(node->right, number);
    }
    
    int sumNumbers(TreeNode* root) {
        if (!root) return 0;
        
        string number;
        dfs(root, number);
        
        return ans;
    }
};