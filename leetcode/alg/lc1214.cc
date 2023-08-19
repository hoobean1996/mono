// leetcode 1214
// Two Sum BSTs

// Two Sum 的变体，在两颗二叉搜索树上的Two Sum
// 一种解法是我们可以利用中序遍历得到两个有序数组
// 然后在两个有序数组上通过双指针查询
// 时间复杂度是 O(n1+ n2)
// 空间复杂度是 O(n1+ n2)
#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> vals1;
    vector<int> vals2;
    
    void inorder(TreeNode* r1, vector<int>& vals) {
        if (!r1) return;
        
        inorder(r1->left, vals);
        
        vals.push_back(r1->val);
        
        inorder(r1->right, vals);
    }
    
    // vals1[i] + vals2[j] == target
    // 首先遍历一遍B数组，并记录到map中
    // 然后遍历A数组，在遍历到过程中，查询map是否有对应的数
    bool findTwoSum(vector<int>& vals1, vector<int>& vals2, int target) {
        unordered_map<int, bool> m;
        for(int i=0; i<vals2.size(); i++) m[vals2[i]] = true;
        
        for(int i=0; i<vals1.size(); i++) {
            if (m.find(target-vals1[i]) != m.end()) return true;
        }
        return false;
    }
    
    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
        inorder(root1, vals1);
        inorder(root2, vals2);
        
        return findTwoSum(vals1, vals2, target);
    }
};

// 第二种方法就是利用非递归遍历二叉树即可
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
        stack<TreeNode*> sk;
        set<int> s;
        
        while(!sk.empty() || root1) {
            while(root1) {
                sk.push(root1);
                root1 = root1->left;
            }
            
            root1 = sk.top(); sk.pop();
            s.insert(target - root1->val);
            root1 = root1->right;
        }
        
        while(!sk.empty() || root2) {
            while(root2) {
                sk.push(root2);
                root2 = root2->left;
            }
            root2 = sk.top(); sk.pop();
            if (s.find(root2->val) != s.end()) return true;
            root2 = root2->right;
        }
        
        return false;
    }
};