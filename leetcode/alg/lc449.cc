// leetcode 449
// Serialze and Deserial BST

// 最直接的方法就是忽略二叉搜索树的性质
// 直接当作二叉树来进行序列化和反序列
// 但是实际上二叉搜索树之需要preorder / postorder就能重建
// 1. 二叉树可以通过preorder | postorder  + inorder 重建
// 2. 二叉搜索树的BST是有序数组
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

class Codec {
public:
    string preorderValues;
    
    // 序列化一颗二叉树
    // 我们可以利用前序遍历把数的每一个节点放入到一个字符串中
    // node, node, ...
    void serial(TreeNode* node) {
        if (!node) return;
        
        preorderValues += to_string(node->val) + ",";
        
        serial(node->left);
        
        serial(node->right);
    }
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        serial(root);
        
        return preorderValues;
    }

    vector<int> split(string data, string delim) {
        data.pop_back();
        int lastIndex = 0;
        int index;
        
        vector<int> ans;
        
        while((index = data.find(delim, lastIndex)) != string::npos) {
            ans.push_back(stoi(data.substr(lastIndex, index - lastIndex)));
            lastIndex = index + delim.length();
        }
        
        if (index != data.length()) {
            ans.push_back(stoi(data.substr(lastIndex, data.length())));
        }
        
        return ans;
    }

    int index = 0;
    TreeNode* build(vector<int>& preorder, int mi, int mx) {
        if (index == preorder.size()) return nullptr;

        if (preorder[index] <= mi || preorder[index] >= mx) return nullptr;
        
        TreeNode* root = new TreeNode(preorder[index]);
        index ++;
        
        root->left = build(preorder, mi, root->val);
        root->right = build(preorder, root->val, mx);
        
        return root;
    }
    
    // Decodes your encoded data to tree.
    // 反序列化一颗二叉树的话，我们首先需要把数据按照 , split分割成节点数组
    // 然后由于二叉搜索树的每个节点都有值的限制，对于根节点来说，是没有的
    TreeNode* deserialize(string data) {
        if (data.length() == 0) return nullptr;
        
        vector<int> nodes = split(data, ",");
        
        return build(nodes, INT_MIN, INT_MAX);
    }
};
