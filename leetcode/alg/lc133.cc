// leetcode 133
// Clone A Graph Deeply

// 深度拷贝一个图，需要在dfs之前进行访问标记
#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

class Solution
{
private:
    map<int, Node *> visited;

public:
    Node *dfsCopy(Node *node)
    {
        if (visited.count(node->val) > 0)
            return visited[node->val];

        Node *h = new Node(node->val);
        // 先标记为已经访问过，在开始复制邻边
        visited[h->val] = h;

        for (int i = 0; i < node->neighbors.size(); i++)
        {
            h->neighbors.push_back(dfsCopy(node->neighbors[i]));
        }
        return h;
    }

    Node *cloneGraph(Node *node)
    {
        if (!node)
            return nullptr;
        return dfsCopy(node);
    }
};