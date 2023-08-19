// leetcode 110
// Balanced Binary Tree

// 判断一棵二叉树是否平衡
// 一定需要注意的时候
// 平衡这个性质是需要每个点都满足的
// isBalanced 内部一定是
//  当前节点满足平衡
//  isBalanced(left)
//  isBalanced(rgith)
// 都需要满足
class Solution {
public:
  int getHeight(TreeNode *node) {
    if (!node)
      return 0;

    return max(getHeight(node->left) + 1, getHeight(node->right) + 1);
  }

  bool isBalanced(TreeNode *root) {
    if (!root)
      return true;

    return (abs(getHeight(root->left) - getHeight(root->right)) <= 1) &&
           isBalanced(root->left) && isBalanced(root->right);
  }
};