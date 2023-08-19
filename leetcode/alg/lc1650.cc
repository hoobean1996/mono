// leetcode 1650
// LCA of Binary Tree III

// 假设我们有一棵二叉树，我们给出树上的两个节点
// 每个节点包含指向父节点的指针
// 求这两个节点的最小公共祖先

// 采取的方法是向上移动法，我们可以分别往上移动，并进行标记
// 如果第二个节点向上移动的时候，遇到了已经标记的节点，证明这个点就是他们的最小公共祖先
#include <bits/stdc++.h>

using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node* parent;

    Node():val(0), left(nullptr), right(nullptr), parent(nullptr) {}
    Node(int x): val(x), left(nullptr), right(nullptr), parent(nullptr) {}
    Node(int x, Node* left, Node* right, Node* parent):val(x), left(nullptr), right(nullptr), parent(nullptr) {}
};


class Solution {
public:
    map<Node*, bool> visited;
    
    Node* lowestCommonAncestor(Node* p, Node * q) {
        while(p) {
            visited[p] = true;
            p = p->parent;
        }
        
        while(q) {
            if (visited.count(q)) return q;
            visited[q] = true;
            q = q->parent;
        }
        
        return nullptr;
    }
};

class Solution {
public:
    // 首先利用p节点把所有的p的祖先节点全部断开链接
    // 但是由于q和p具有lca
    // 那么当我们利用q来访问的时候，走到lca节点之后
    // 就走不动了
    // 所以可以优化到O(1)
    Node* lowestCommonAncestor(Node* p, Node* q) {
        while(p->parent) {
            Node* parent = p->parent;
            p->parent = nullptr;
            p = parent;
        }

        while(q->parent) q = p->parent;
        return q;
    }
}