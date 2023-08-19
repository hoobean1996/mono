// leetcode 778
// Swim in Rising Water 

// 给定一个n*n的矩阵 
// 每个格子的海拔是不同的 grid[i][j]

// 开始下雨了，在任何时间t，所有water的深度都是t
// 你可以在不同的格子之间游泳
// 如果两个相邻的格子最多为t
// 可以游无限的距离

// 方案一：二分搜索 + DFS
// 考虑搜索的上限是最大值，
// 对于每个可能的t，我们用dfs判断是否能够全部游过
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    
    // BFS 来check能否游过去
    bool check(int t, vector<vector<int>>& grid) {
        int n = grid.size();
        
        set<int> seen;
        queue<int> q;
        // 把二维坐标转化为一维坐标
        q.push(0);
        
        while(!q.empty()) {
            // 当队列不为空的时候，取出对头的一维坐标，并转化为二维坐标
            int k = q.front(); q.pop();
            int x = k / n;
            int y = k % n;
            // 如果到达目的地，直接返回
            if (x == n-1 && y == n-1) return true;
            
            // 遍历当前坐标的四个方向，如果grid[nx][ny] <= t，意味着可以游过去，所以添加到队列中
            for(int i=0; i<4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx >= 0 && ny >= 0 && nx < n && ny < n && seen.count(nx * n + ny) == 0 && grid[nx][ny] <= t) {
                    q.push(nx*n + ny);
                    seen.insert(nx*n + ny);
                }
            }
        }
        
        return false;
    }
    

    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int l = grid[0][0];
        int r = n * n;
        
        while(l <= r) {
            int mid = l + (r - l) / 2;
            // 判断当前的值能够游过去，如果不能游过去的话，考虑右侧区间
            // 否则的话，考虑左侧区间
            if (!check(mid, grid)) l = mid + 1;
            else r = mid - 1;
        }
        
        return l;
    }
    
    
};