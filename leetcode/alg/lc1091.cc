// leetcode 1091
// Shortest Path in Binary Matrix

// 给定一个矩阵，里面是0和1，我们希望从(0,0) -> 右下角的位置
// 要求每一个步骤都必须走0的格子，但是可以走八个方向
// 基本上还是BFS思路来解决
// 把起点放入到队列中，不断从队列中取出处理即可

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        if (grid[0][0] == 1) return -1;
        
        // 创建一个队列每个元素是 {x, y}, d
        // 坐标和距离
        // 初始化的时候把原点放入
        // 然后利用vis集合来进行去重
        queue<pair<pair<int, int>, int>> q;
        q.push({{0, 0}, 1});
        
        int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
        int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
        set<pair<int, int>> vis;
        vis.insert({0, 0});
        
        while(!q.empty()) {
            auto [pos, d] = q.front();
            q.pop();
            
            if (pos.first == m-1 && pos.second == n-1) {
                return d;
            }
            
            for(int k=0; k<8; k++) {
                int nx = pos.first + dx[k];
                int ny = pos.second + dy[k];
                
                if (nx >= 0 && ny >= 0 && nx < m && ny < n && grid[nx][ny] == 0) {
                    if (vis.find({nx, ny}) == vis.end()) {
                        q.push({{nx, ny}, d+1});
                        vis.insert({nx, ny});
                    }
                }
            }
        }
        
        return -1;
    }
};