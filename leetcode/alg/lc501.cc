// leetcode 501
// Find Mode in Binary Search Tree

// Modes 是出现次数最多的元素
// 我们可以利用中序遍历得到一个有序数组，然后统计次数即可
#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> vals;

    void inorder(TreeNode* root) {
        if (!root) return;

        inorder(root->left);
        vals.push_back(root->val);
        inorder(root->right);
    }

    vector<int> findMode(TreeNode* root) {
        inorder(root);

        if (vals.size() == 1) return vals;

        int prev = vals[0];
        int count = 1;
        int maxCount = 1;

        vector<int> ans;

        for (int i = 1; i < vals.size(); i++) {
            if (vals[i] == prev) {
                count++;
            }
            else {
                if (count >= maxCount) {
                    if (count > maxCount) ans.clear();
                    ans.push_back(prev);
                    maxCount = count;
                }
                prev = vals[i];
                count = 1;
            }
        }

        if (count >= maxCount) {
            if (count > maxCount) ans.clear();
            ans.push_back(prev);
        }

        return ans;
    }
};

// 直接利用inorder实现的
// 不需要额外的数组
class Solution {
public:
    vector<int> ans;
    // flag用于判断是否为第一个节点
    int flag = 0;
    // prev 记录前一个节点的值
    int prev;
    // max 记录的是当前放入结果中的值出现的次数
    int max = 1;
    // temp 记录的是当前的值一共出现的次数
    int temp = 1;
    
    void inorder(TreeNode* node) {
        if (!node) return;
        
        inorder(node->left);
        
        if (flag == 0) {
            flag = 1;
            prev = node->val;
            ans.push_back(prev);
        }
        else {
            if (prev == node->val) temp ++;
            else temp = 1;
            if (temp > max) {
                max = temp;
                ans.clear();
                ans.push_back(prev);
            }
            else if (temp == max) ans.push_back(node->val);
            prev = node->val;
        }
        
        inorder(node->right);
    }
    
    vector<int> findMode(TreeNode* root) {
        if (!root) return {};
        inorder(root);
        return ans;
    }
};