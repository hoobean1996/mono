// leetcode 987
// Vertical Order Traversal of a Binary Tree
// 给定一棵二叉树，我们希望按照Vertical的顺序来遍历它

#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right) {}
};

class Solution {
public:
    unordered_map<int, vector<pair<int, int>>> columns;
    int minColumn = 1e9;
    int maxColumn = -1e9;
    vector<vector<int>> ans;
    
    void dfs(TreeNode* node, int x, int y) {
        if (!node) return;
        
        columns[y].push_back({x, node->val});
        if (y < minColumn) minColumn = y;
        
        if (y > maxColumn) maxColumn = y;
        
        dfs(node->left, x + 1, y - 1);
        dfs(node->right, x + 1, y + 1);
    }
    
    void transform() {
        for(int col=minColumn; col <= maxColumn; col++) {
            vector<pair<int, int>> info = columns[col];
            
            sort(info.begin(), info.end(), [](const pair<int, int>& p1, const pair<int, int>& p2 ){
                return p1.first < p2.first || (p1.first == p2.first && p1.second < p2.second);             
            });
            
            vector<int> vals;
         
            for(int i=0; i<info.size(); i++) vals.push_back(info[i].second);
            
            ans.push_back(vals);
        }
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(!root) return {};
        
        dfs(root, 0, 0);
        
        transform();
        
        return ans;
    }
};