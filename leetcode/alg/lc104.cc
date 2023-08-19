// leetcode 104
// Maximum Depth of Binary Tree

// 如果是求二叉树的最大高度的话，我们就直接自底向上传递高度即可
#include <bits/stdc++.h>

using namespace std;
// 需要注意的是求解最小高度和最大高度的区别
// 最小高度的话不能递归空节点
class Solution {
public:
  int maxDepth(TreeNode *root) {
    if (!root)
      return 0;

    int l = maxDepth(root->left);

    int r = maxDepth(root->right);

    return max(l, r) + 1;
  }
};