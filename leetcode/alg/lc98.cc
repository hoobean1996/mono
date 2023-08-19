// leetcode 98
// Validate BST
// 验证一棵二叉搜索树的方法有两种
// 1. 考虑每个节点的性质
// 2. 考虑中序遍历的性质

class Solution {
public:
  // 对于一个二叉树节点来说，它的取值是有要求的
  // 左小右大
  bool valid(TreeNode *node, long mi, long mx) {
    // 空节点合法
    if (!node)
      return true;
    // 如果当前的节点值，<=比当前的最小值 或者 >= 最大值 都不合法
    if ((long)node->val <= mi || (long)node->val >= mx)
      return false;

    // 同时递归的验证它的左右子节点
    return valid(node->left, mi, node->val) &&
           valid(node->right, node->val, mx);
  }
  // 注意这个范围，数据类型应该是long
  // INT_MAX + 1
  // INT_MIN - 1
  bool isValidBST(TreeNode *root) {
    return valid(root, -2147483649, 2147483648);
  }
};

// 维护一个prev指针
class Solution {
public:
  TreeNode *prev = nullptr;
  bool ans = true;

  // 中序遍历一棵二叉搜索树得到的是有序的数组
  void inorder(TreeNode *node) {
    if (!node)
      return;
    inorder(node->left);

    // prev 是前驱节点
    if (prev && node->val <= prev->val) {
      ans = false;
      return;
    }
    prev = node;

    inorder(node->right);
  }

  bool isValidBST(TreeNode *root) {
    inorder(root);
    return ans;
  }
};
