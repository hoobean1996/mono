// leetcode 314
// Binary Tree Vertical Order Traversal

// 二叉树的Vertical Order 遍历
// 相当于给二叉树的节点打上网格坐标，root节点是(0,0)

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
    // col -> {rows}
    map<int, vector<pair<int, int>>> columnTable;
    int minCol = 0;
    int maxCol = 0;
    
    void dfs(TreeNode* node, int row, int col) {
        if (!node) return;
        // 放入到对应的col中
        columnTable[col].push_back(make_pair(row, node->val));
        // 记录左右边界
        minCol = min(minCol, col);
        maxCol = max(maxCol, col);
        dfs(node->left, row+1, col-1);
        dfs(node->right, row+1, col+1);
    }
    
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root) return ans;
        
        dfs(root, 0, 0);
        // 因为我们需要按照col显示，所以利用col作为map的key
        // 时间复杂度是 W * HlogH
        // W是树的宽度
        // H是树的深度
        // N < W * H
        // 整体上来就是 O(N)的复杂度
        for(int i=minCol; i<=maxCol; i++) {
            // 对于每个column的元素，我们按照row从小到大排序
            sort(columnTable[i].begin(), columnTable[i].end(), [](const pair<int, int>& p1, const pair<int, int>& p2){
               return p1.first < p2.first; 
            });
            vector<int> tmp;
            for(const pair<int, int>& p: columnTable[i]) {
                tmp.push_back(p.second);
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};