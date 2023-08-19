// leetcode 272
// Closest Binary Search Tree Value II

// 给定一棵二叉搜索树 和一个目标值 target
// 返回k个离该目标值最近的值

#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    vector<pair<int, double>> vals;

    void inorder(TreeNode *node, double target)
    {
        if (!node)
            return;

        inorder(node->left, target);

        vals.push_back({node->val, abs(node->val - target)});

        inorder(node->right, target);
    }

    int partition(int l, int r)
    {
        auto [val, diff] = vals[r];

        int i = l - 1;
        for (int j = l; j < r; j++)
        {
            auto [curVal, curDiff] = vals[j];
            if (curDiff <= diff)
            {
                swap(vals[++i], vals[j]);
            }
        }

        swap(vals[++i], vals[r]);

        return i;
    }

    vector<int> closestKValues(TreeNode *root, double target, int k)
    {
        inorder(root, target);

        int l = 0;
        int r = vals.size() - 1;

        while (l <= r)
        {
            int m = partition(l, r);
            if (m == k)
            {
                break;
            }
            else if (m < k)
            {
                l = m + 1;
            }
            else if (m > k)
            {
                r = m - 1;
            }
        }

        vector<int> ans;

        for (int i = 0; i < k; i++)
            ans.push_back(vals[i].first);

        return ans;
    }
};