// leetcode 331
// Verify Preorder Serialization of a Binary Tree
// 给定一棵二叉树的前序遍历的序列
// 我们想要验证是否为一棵有效的二叉树

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> split(string preorder) {
        vector<string> ans;

        int lastIndex = 0;
        int index;

        while ((index = preorder.find(",", lastIndex)) != string::npos) {
            ans.push_back(preorder.substr(lastIndex, index - lastIndex));
            lastIndex = index + 1;
        }

        if (lastIndex != preorder.length()) {
            ans.push_back(preorder.substr(lastIndex, preorder.length() - lastIndex));
        }

        return ans;
    }

    bool isValidSerialization(string preorder) {
        int slots = 1;
        vector<string> nodes = split(preorder);

        // 考虑一个可以有的节点计数器 slots
        // 初始化为1
        // 每消耗一个节点，就减一
        for (const string node : nodes) {
            slots--;
            // 如果slots < 0，肯定是不对的
            if (slots < 0) return false;

            // 对于每个新的节点, 可以拥有两个子节点 slots += 2
            if (node != "#") slots += 2;
        }

        // 最后一定是刚刚消耗完所有的计数器才行
        return slots == 0;
    }
};