// leetcode 323
// Number of Connected Components in an Undirected Graph
// 求连通分量

// 并查集的直接利用
// 首先假设连通分量为节点数，然后每union两个节点，就减一
#include <bits/stdc++.h>

using namespace std;

int fa[2010];

void init() {
    for(int i=0; i<2010; i++) fa[i] = i;
}

int find(int x) {
    if (x != fa[x]) fa[x] = find(fa[x]);
    return fa[x];
}

bool un(int x, int y) {
    int a = find(x);
    int b = find(y);
    
    if (a != b) {
        fa[b] = a;
        return true;
    }
    return false;
}


class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        int ans = n;
        
        init();
        
        for(int i=0; i<edges.size(); i++) {
            int a = edges[i][0];
            int b = edges[i][1];
            
            if (un(a, b)) ans--;
        }
        
        return ans;
    }
};