// leetcode 1305
// All Elements in Two Binary Search Trees

// 给定两颗二叉搜索树，我们希望把所有的节点的值收集起来，并按照非降序排列。
// 直观的想法是我们可以利用中序遍历得到两个有序的数组
// 然后把问题转换为合并有序数组
// 整体是能够在O(n1+n2)完成的
// 空间复杂度也是O(n1+n2)
// 通过非递归遍历二叉树就能更有效的解决

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
     void inorder(TreeNode* r, vector<int>& ans) {
         if (!r) return;
         
         inorder(r->left, ans);
         
         ans.push_back(r->val);
         
         inorder(r->right, ans);
    } 
    
    vector<int> merge(vector<int>& vals1, vector<int>& vals2) {
        int i = 0;
        int j = 0;
        int l1 = vals1.size();
        int l2 = vals2.size();
        vector<int> ans;
        
        while(i < l1 && j < l2) {
            if (vals1[i] <= vals2[j]) ans.push_back(vals1[i++]);
            else ans.push_back(vals2[j++]);
        }
        
        while(i < l1) ans.push_back(vals1[i++]);
        while(j < l2) ans.push_back(vals2[j++]);
        
        return ans;
    }
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> vals1;
        vector<int> vals2;
        
        inorder(root1, vals1);
        inorder(root2, vals2);
        
        return merge(vals1, vals2);
    }
};

// 通过非递归遍历二叉树来合并两颗BST
class Solution {
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        stack<TreeNode*> sk1;
        stack<TreeNode*> sk2;
        vector<int> ans;
        
        while(root1 || root2 || sk1.size() || sk2.size()) {
            // 首先把两棵树的root节点及其左儿子放入到栈中 
            while(root1) {
                sk1.push(root1);
                root1 = root1->left;
            }
            while(root2) {
                sk2.push(root2);
                root2 = root2->left;
            }
            
            // 如果第二个栈为空 或者是 栈1不为空，同时栈1的栈顶小于栈2的栈顶，弹出并放入结果中
            // 更新root1 = root1->right;
            if (sk2.empty() || !sk1.empty() && sk1.top()->val <= sk2.top()->val) {
                root1 = sk1.top(); sk1.pop();
                ans.push_back(root1->val);
                root1 = root1->right;
            }
            else {
                root2 = sk2.top(); sk2.pop();
                ans.push_back(root2->val);
                root2 = root2->right;
            }
        }
        
        return ans;
    }
};