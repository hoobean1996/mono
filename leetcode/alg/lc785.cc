// leetcode 785
// Is Graph Bipartite

// 给定一个图，这个图是用邻接表来表示的
// 判断一个图是否为二分图
// 考虑递归的给一个图染色
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // 顶点染色的情况 初始化都是0
    int color[110];
    
    // dfs给当前的顶点v染色成c
    // 然后递归的处理它的相领节点，如果某个相领节点已经被染色，那么肯定返回false
    // 如果还没有染色，但是尝试染色为 -c的时候，失败 也肯定不行
    bool dfs(int v, int c, vector<vector<int>>& g) {
        color[v] = c;
        
        // 递归处理与当前顶点v相连的所有顶点
        for(int i=0; i<g[v].size(); i++) {
            if (color[g[v][i]] == c) return false;
            if (color[g[v][i]] == 0 && !dfs(g[v][i], -c, g)) return false;
        }
        
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        for(int i=0; i<graph.size(); i++) {
            if (!color[i]) {
                if (!dfs(i, 1, graph)) return false;
            }
        }
        
        return true;
    }
};