// leetcode 261
// Graph Valid Tree

// 检查一个图是一颗树
// 可以利用并查集来统计
// 一个图要是一棵树的话，边只能是N-1条
// 然后我们尝试放入到并查集中，如果merge操作存在任何一次失败，则证明不是树
// 因为一棵树上的任何一条边被删去，都会导致连通分量增加一个

#include <bits/stdc++.h>

using namespace std;

int fa[2010];

void init()
{
    for (int i = 0; i < 2010; i++)
        fa[i] = i;
}

int find(int x)
{
    if (x != fa[x])
        fa[x] = find(fa[x]);
    return fa[x];
}

bool un(int x, int y)
{
    int a = find(x);
    int b = find(y);
    if (a != b)
    {
        fa[b] = a;
        return true;
    }
    return false;
}

class Solution
{
public:
    bool validTree(int n, vector<vector<int>> &edges)
    {
        // N个节点，必须是N-1个边
        if (edges.size() != n - 1)
            return false;

        // 利用并查集来实现
        init();

        for (int i = 0; i < edges.size(); i++)
        {
            int a = edges[i][0];
            int b = edges[i][1];
            
            if (!un(a, b))
                return false;
        }

        return true;
    }
};