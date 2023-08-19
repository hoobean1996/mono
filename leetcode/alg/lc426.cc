// leetcode 426
// Convert Binary Search Tree to Sorted Doubly Linked List

// 给定一棵二叉搜索树，我们希望把它转换为一根循环链表
// 基本的思路是首先通过中序遍历变成一根链表，然后在完成首位相连
struct Node {
    int val;
    Node* left;
    Node* right;

    Node() : val(0), left(nullptr), right(nullptr) {}
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
    Node(int x, Node* left, Node* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    Node* prev = nullptr;

    void dfs(Node* root) {
        if (!root) return;
        dfs(root->left);

        //更新prev指针为left 
        root->left = prev;
        if (prev) prev->right = root;
        //更新prev指针为root
        prev = root;
        dfs(root->right);
    }

    Node* treeToDoublyList(Node* root) {
        if (!root) return root;

        dfs(root);

        while (root && root->left != nullptr) root = root->left;

        root->left = prev;
        prev->right = root;

        return root;
    }
};