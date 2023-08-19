// leetcode 297
// Serilize and Deserilize Binary Tree
// 二叉树的序列化与反序列化
// 直接简单的preorder遍历二叉树进行序列化即可
// 反序列化需要首先将字符串分割为节点的字符串数组，然后依次构建
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

class Codec {
public:
    void rserialize(TreeNode* root, string& str) {
        if (!root) str += "null,";
        else {
            str += to_string(root->val) + ",";
            rserialize(root->left, str);
            rserialize(root->right, str);
        }
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string str;
        rserialize(root, str);
        return str;
    }

    int index = 0;
    TreeNode* rdeserialize(vector<string>& l) {
        if (index == l.size()) return nullptr;

        if (l[index] == "null") {
            index ++;
            return nullptr;
        }

        TreeNode* root = new TreeNode(stoi(l[index]));
        index ++;

        root->left = rdeserialize(l);
        root->right = rdeserialize(l);

        return root;
    }

    vector<string> split(string data) {
        vector<string> ans;
        int lastIndex = 0;
        int index;
        while ((index = data.find(",", lastIndex)) != string::npos) {
            ans.push_back(data.substr(lastIndex, index - lastIndex));
            lastIndex = index + 1;
        }
        if (lastIndex != data.length()) ans.push_back(data.substr(lastIndex, data.length() - lastIndex));
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> datas = split(data);

        reverse(datas.begin(), datas.end());

        return rdeserialize(datas);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));