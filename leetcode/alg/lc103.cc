// leetcode 103
// Binary Tree Zigzag Level Order Trversal

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        if (!root)
            return {};

        queue<TreeNode *> q;
        q.push(root);

        vector<vector<int>> ans;

        bool needReverse = false;
        while (!q.empty())
        {
            int n = q.size();

            vector<int> row;
            for (int i = 0; i < n; i++)
            {
                TreeNode *u = q.front();
                q.pop();
                row.push_back(u->val);

                if (u->left)
                    q.push(u->left);
                if (u->right)
                    q.push(u->right);
            }
            if (needReverse)
            {
                reverse(row.begin(), row.end());
            }
            needReverse = !needReverse;
            ans.push_back(row);
        }

        return ans;
    }
};