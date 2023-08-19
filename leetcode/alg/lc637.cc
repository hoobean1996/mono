// leetcode 637
// Average of Levels in Binary Tree

// 给定一棵二叉树，我们希望求出每一层的平均值
// 基本思路就是BFS，然后每层计算平均值即可
// 如果是DFS的话，如果用一个map来记录(height, sum)的值

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
    vector<double> averageOfLevels(TreeNode* root) {
        if (!root) return {};

        queue<TreeNode*> q;
        q.push(root);
        vector<double> ans;
        while (!q.empty()) {
            int n = q.size();
            double sum = 0;
            for (int i = 0; i < n; i++) {
                TreeNode* u = q.front(); q.pop();
                sum += u->val;
                if (u->left) q.push(u->left);
                if (u->right) q.push(u->right);
            }
            ans.push_back(sum / n);
        }

        return ans;
    }
};