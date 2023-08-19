// leetcode 116
// Populating Next Right Pointers in Each Node
#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};


class Solution {
public:
    void bfs(Node* root) {
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()) {
            int n = q.size();
            vector<Node*> tmp;
            for(int i=0; i<n; i++) {
                Node* top = q.front();
                q.pop();
                tmp.push_back(top);
                if (top->left) q.push(top->left);
                if (top->right) q.push(top->right);
            }
            
            for(int i=0; i<tmp.size()-1; i++) tmp[i]->next = tmp[i+1];
        }
    }
    
    Node* connect(Node* root) {
        if (!root) return root;
        bfs(root);
        return root;
    }
};