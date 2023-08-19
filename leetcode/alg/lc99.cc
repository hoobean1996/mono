// leetcode 99
// Recovery Binary Search Tree
// 考虑中序遍历二叉搜索树可以得到有序列表
// 但是经过交换以后，有两个元素的位置是不对的
// 判断的标准就是nums[i] > nums[i+1]
// 一共会有两个i满足上面的条件
// x，y分别是 第一种情况的i，和第二种情况的i+1
// 在recover的时候就遍历二叉树，如果和x相同就换成y，如果和y相同就换成x，然后退出
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  vector<int> vals;

  void inorder(TreeNode *node) {
    if (!node)
      return;

    inorder(node->left);

    vals.push_back(node->val);

    inorder(node->right);
  }

  pair<int, int> find() {
    pair<int, int> p;

    int i = 0;
    while (i < vals.size() - 1) {
      if (vals[i] > vals[i + 1]) {
        p.second = vals[i];
        break;
      }
      i++;
    }

    int j = vals.size() - 1;
    while (j > i) {
      if (vals[j] < vals[j - 1]) {
        p.first = vals[j];
        break;
      }
      j--;
    }

    return p;
  }

  void recover(TreeNode *node, int x, int y, int count) {
    if (node) {
      if (node->val == x || node->val == y) {
        node->val = node->val == x ? y : x;
        if (--count == 0)
          return;
      }
      recover(node->left, x, y, count);
      recover(node->right, x, y, count);
    }
  }

  void recoverTree(TreeNode *root) {
    inorder(root);

    auto [x, y] = find();

    recover(root, x, y, 2);
  }
};