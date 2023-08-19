// leetcode 310
// Minimum Height Trees

// 最小高度树
// 这道题是说给定一棵树，我们要重新选一个节点来作为根节点，使得整棵树的高度最小
// 无向图拓扑排序的感觉
// 拓扑排序，利用叶子节点入手，每次删除所有的叶子节点以后，并更新与叶子节点相连的边
// 从而得到新的叶子节点

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges)
    {
        if (n < 2) return {0};

        // 构造图的领边
        vector<set<int>> neighbors(n, set<int>());
        for (int i = 0; i < edges.size(); i++)
        {
            int s = edges[i][0];
            int e = edges[i][1];
            neighbors[s].insert(e);
            neighbors[e].insert(s);
        }

        // 在所有节点中，size=1的就是当前的叶子节点，
        vector<int> leaves;
        for (int i = 0; i < n; i++)
        {
            if (neighbors[i].size() == 1) leaves.push_back(i);
        }

        int remains = n;

        while (remains > 2)
        {
            remains -= leaves.size();
            vector<int> newLeaves;
            for (const int leaf : leaves)
            {
                // 找到当前叶子节点的相连的节点
                // 然后更新该节点的neighbor信息
                int neighbor = *(neighbors[leaf].begin());
                neighbors[neighbor].erase(leaf);
                if (neighbors[neighbor].size() == 1)
                    newLeaves.push_back(neighbor);
            }
            leaves = newLeaves;
        }

        // 最后剩下的都是MHT的根
        return leaves;
    }
};