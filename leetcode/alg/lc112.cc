// leetcode 112
// Path Sum

// PathSum 是否存在一条分支满足所有节点的和为给定的target
class Solution {
public:
  // dfs 表示当前需要的值
  // dfs(node, targetSum)
  // 是需要传递到叶子节点的时候，判断是否满足
  bool dfs(TreeNode *node, int targetSum) {
    if (!node)
      return false;

    // 如果当前节点的值 == targetSum，但是注意
    // 必须要是叶子节点
    if (node->val == targetSum && node->left == nullptr &&
        node->right == nullptr)
      return true;

    // 如果该节点不是的话，继续递归下去
    return dfs(node->left, targetSum - node->val) ||
           dfs(node->right, targetSum - node->val);
  }

  bool hasPathSum(TreeNode *root, int targetSum) {
    if (!root)
      return false;

    if (dfs(root, targetSum))
      return true;

    return false;
  }
};