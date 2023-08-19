// leetcode 286
// Walls and Gates

// Walls and Gates 这道题是说地图中有很多门和墙，还有空地，我们需要找到所有的
// 空地到最近的门的距离。
// 由于门的值本身就是1
// 我们就可以原地修改即可
// 从门开始BFS，然后相邻的都不断的增加1

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  const int EMPTY = 2147483647;
  const int GATE = 0;

  // 四个方向
  int dx[4] = {-1, 0, 1, 0};
  int dy[4] = {0, 1, 0, -1};

  void wallsAndGates(vector<vector<int>> &rooms) {
    int m = rooms.size();
    if (m == 0)
      return;

    int n = rooms[0].size();

    queue<pair<int, int>> q;

    // 初始化放入门
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (rooms[i][j] == GATE)
          q.push(make_pair(i, j));
      }
    }

    while (!q.empty()) {
      auto [x, y] = q.front();
      q.pop();

      for (int k = 0; k < 4; k++) {
        int r = x + dx[k];
        int c = y + dy[k];

        if (r < 0 || c < 0 || r >= m || c >= n || rooms[r][c] != EMPTY)
          continue;

        rooms[r][c] = rooms[x][y] + 1;

        q.push(make_pair(r, c));
      }
    }
  }
};
