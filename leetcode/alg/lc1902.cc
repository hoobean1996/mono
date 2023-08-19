// leetcode 1902
// Depth of BST Given Insertion Order

// 给定一个数组，我们需要把利用该数组来构建一棵二叉树
// 我们采用不断插入每个元素的方法来构建二叉树
// 我们想知道这颗二叉树的最大深度是多少

#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
    TreeNode* left;
    TreeNode* right;
    int val;
    int depth;
    TreeNode(int val, int depth) : left(nullptr), right(nullptr), val{val}, depth{depth} {}
};

class Solution {
public:
    // root是BST的根节点
    int maxDepthBST(vector<int>& order) {
        TreeNode* root = nullptr;
        TreeNode* low = nullptr;
        TreeNode* high = nullptr;

        int highest = 0;

        for (const int v: order)
        {   
            // 对于每个待插入的节点来说
            // 如果他比最小值小/最大值大是很简单的
            // 直接插入
            // 否则的话，就从根节点移动到合适的位置插入即可
            // depth代表当前节点的高度
            int depth = 1;
			
            // 如果没有根节点，创建一个根节点，深度为1
            // 同时更新low 和 high
            if (!root) {
                root = new TreeNode(v, 1);
                low = root;
                high = root;
            }
            // 如果已经有根节点了，同时当前待插入的值比low->val还要小
            // 那么应该插入到low节点的左侧
            // 同时low节点更新为更low的节点
            else if (v < low->val)
            {
                low->left = new TreeNode(v, low->depth + 1);
                low = low->left;
                depth = low->depth;
            }
            // 如果待插入的值比high的值要大
            // 那么应该插入到high到右侧
            // 同时更新high节点
            else if (v > high->val)
            {
                high->right = new TreeNode(v, high->depth + 1);
                high = high->right;
                depth = high->depth;
            }
            // 如果不满足上面两种情况
            // 就应该考虑从root开始移动
            // 找到合适的位置
            else
            {
                TreeNode *curr = root;
                while (true)
                {   
                    // 如果待插入的值比cur的小，移动到左侧，否则移动到右侧
                    // 同时记录深度
                    TreeNode* dest = v < curr->val ? curr->left : curr->right;
                    ++depth;
                    // 如果有dest节点，移动
                    // 如果没有就插入到这里
                    if (dest) curr = dest;
                    else
                    {
                        dest = new TreeNode(v, depth);
                        break;
                    }
                }
            }
            highest = max(highest, depth);
        }
        return highest;
    }
};