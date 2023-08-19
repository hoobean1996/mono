// leetcode 317
// Shortest Distance from All Buildings

// 给定一张地图，上面有建筑，空地和障碍物，我们想知道到所有建筑物的最短距离是多少（因为有很多空地
// 肯定有一个空地到所有建筑的距离是最小的
// 一种方法是我们从空地开始遍历bfs，得到最短的距离
// 但是这道题是从建筑物开始出发
// 1. 建筑物的数量相对于空地较少

// 0 代表空地
// 1 代表建筑
// 2 代表障碍物

// 这道题和A Large island 有关键点
// 这道题指导我们如何区分不同的BFS轮次
// 那道题指导我们如何区分不同的DFS轮次
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int dx[4] = {-1, 0, 1, 0};
  int dy[4] = {0, 1, 0, -1};

  int EMPTY = 0;

  vector<vector<int>> total;

  int bfs(vector<vector<int>> &grid, int r, int c) {
    int ans = INT_MAX;

    queue<pair<pair<int, int>, int>> q;
    q.push({{r, c}, 0});

    while (!q.empty()) {
      auto [pos, d] = q.front();
      q.pop();
      for (int k = 0; k < 4; k++) {
        int nx = pos.first + dx[k];
        int ny = pos.second + dy[k];
        if (nx >= 0 && nx < grid.size() && ny >= 0 && ny < grid[0].size() &&
            grid[nx][ny] == EMPTY) {
          total[nx][ny] += d + 1;
          // 注意格子也需要 - 1
          grid[nx][ny]--;

          q.push({{nx, ny}, d + 1});

          ans = min(ans, total[nx][ny]);
        }
      }
    }
    // EMPTY用于表示当前轮次编号
    // 所以每次都需要在队列处理完成以后在--
    EMPTY--;

    return ans;
  }

  int shortestDistance(vector<vector<int>> &grid) {
    total = vector<vector<int>>(grid.size(), vector<int>(grid[0].size(), 0));
    int ans = INT_MAX;
    for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid[0].size(); j++) {
        // 注意这里，要的就是最后一轮的结果
        if (grid[i][j] == 1) {
          ans = bfs(grid, i, j);
          // 如果某轮出现了INT_MAX 证明不可达
          if (ans == INT_MAX)
            return -1;
        }
      }
    }

    return ans;
  }
};