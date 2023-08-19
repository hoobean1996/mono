// leetcode 111
// Minimum Depth of Binary Tree

// 给定一棵二叉树，我们想知道最小高度是多少
// 某个节点的高度定义为叶子的高度。
// 我们把高度从root节点开始传递，在dfs中判断如果当前的高度比最大高度小，并且是叶子节点的话
// 就更新答案
// 求解二叉树的最高高度是需要从叶子结点传递到根节点
// 而求解二叉树的最小高度是需要从根节点传入一个值，直到根节点在确认
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int ans = 99999;

  void dfs(TreeNode *root, int h) {
    if (!(root->left) && !(root->right)) {
      if (h <= ans)
        ans = h;
    }
    if (root->left)
      dfs(root->left, h + 1);
    if (root->right)
      dfs(root->right, h + 1);
  }

  int minDepth(TreeNode *root) {
    if (!root)
      return 0;

    dfs(root, 1);

    return ans;
  }
};