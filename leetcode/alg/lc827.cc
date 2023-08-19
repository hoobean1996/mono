// leetcode 827
// Making A Large Island

// 给定一个矩阵，其中有多片岛屿，我们希望将其中的某一个位置相连，使得
// 我们能够得到更大的岛屿。

// 通过DFS给网格划分连通量 （将值改为 正确的值）
// 然后得到当前的最大值（在不改任何0点情况下的最大值）
// 然后遍历所有的0的点，然后尝试访问它的四周，由于我们已经将网格上的所有点
// 都改为了对应的连通分量的值
// 如果0周围有连通分量，我们就可以连成一片，得到更大的值
#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    int _size;
    
    int dfs(vector<vector<int>>& _grid, int x, int y, int val) {
        int ans = 1;
        _grid[x][y] = val;
        
        for(int k=0; k<4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            
            // 由于我们已经把改格子改为val了，所以不会出现死循环
            if (nx >= 0 && ny >= 0 && nx < _size && ny < _size && _grid[nx][ny] == 1) {
                ans += dfs(_grid, nx, ny, val);
            }
        }
        return ans;
    }
    
    int largestIsland(vector<vector<int>>& grid) {
        _size = grid.size();
        
        // 下标是编号，area[i]是对应的面积
        // 由于地图是01构成的，所以我们从2开始用
        int val = 2;
        vector<int> area(_size*_size + 2);
        
        // 遍历整个地图，如果是1的话，利用dfs找到对应的面积，
        for(int x=0; x<_size; x++) {
            for(int y=0; y<_size; y++) {
                if (grid[x][y] == 1) {
                    // 每次找到一片连通的岛屿以后，我们就把val ++
                    // 避免下一次染色的时候相同
                    // 同时我们记录当前染色情况的岛屿的连通面积是多少
                    area[val] = dfs(grid, x, y, val);
                    val ++;
                }
            }
        }
        
        // 首先我们遍历所有的面积，找到当前的最大面积
        int ans = *max_element(area.begin(), area.end());
        
        // 接下来我们尝试去找到每一片空地，看看如果把它变成岛屿以后
        // 能否得到更大的岛屿
        for(int x=0; x<_size; x++) {
            for(int y=0; y<_size; y++) {
                if (grid[x][y] == 0) {
                    
                    // 记录该0周围的连通分量
                    // 然后把周围的面积全部加起来
                    // 为什么要用set，是因为可能是同属一个连通分量，这种情况下就不应该重复计算
                    set<int> seen;
                    for(int k=0; k<4; k++) {
                        int nx = x + dx[k];
                        int ny = y + dy[k];
                        // grid[nx][ny] > 1 证明是某个连通分量，所以可以记录
                        if (nx >= 0 && ny >= 0 && nx < _size & ny < _size && grid[nx][ny] > 1) seen.insert(grid[nx][ny]);
                    }
                    int bns = 1;
                    for(const int i: seen) bns += area[i];
                    ans = max(ans, bns);
                }
            }
        }
        return ans;
    }
};