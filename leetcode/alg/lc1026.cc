// leetcode 1026
// Maximum Difference Between Node and Ancestor

// 给定一个二叉树，找到两个节点a和b，其中a是b的祖先，问他们的最大差值是多少

// 考虑到在同一条路径的所有节点，都满足给定的祖孙关系
// 所以我们需要找到一条路径上的最大最小值即可
// 递归的时候带上当前路径的最大值最小值即可
// 到叶子节点的时候，就得到了该路径的值
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
    int helper(TreeNode* root, int curMax, int curMin) {
        if (!root) return curMax - curMin;
        
        curMax = max(curMax, root->val);
        curMin = min(curMin, root->val);
        
        int l = helper(root->left, curMax, curMin);
        int r = helper(root->right, curMax, curMin);
        
        return max(l, r);
    }
    
    int maxAncestorDiff(TreeNode* root) {
        if (!root) return 0;
        
        return helper(root, root->val, root->val);
    }
};