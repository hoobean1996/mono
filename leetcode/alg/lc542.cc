// lc542
// 01 Matrix
// 给定一个矩阵，求出每个cell到最近的0的距离。

class Solution {
public:
  vector<vector<int>> updateMatrix(vector<vector<int>> &grid) {
    int m = grid.size();
    int n = grid[0].size();

    // 构造一个dp矩阵
    vector<vector<int>> dp(m, vector<int>(n, INT_MAX - 1));

    // 初始化
    // 如果是i, j位置的值是0， 那么dp[i][j] = 0
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == 0) {
          dp[i][j] = 0;
          continue;
        }
        // 处理列
        if (j >= 1)
          dp[i][j] = ::min(dp[i][j], dp[i][j - 1] + 1);
        // 处理行
        if (i >= 1)
          dp[i][j] = ::min(dp[i][j], dp[i - 1][j] + 1);
      }
    }

    for (int i = m - 1; i >= 0; i--) {
      for (int j = n - 1; j >= 0; j--) {
        if (grid[i][j] != 0) {
          if (j < n - 1) {
            dp[i][j] = ::min(dp[i][j], dp[i][j + 1] + 1);
          }
          if (i < m - 1) {
            dp[i][j] = ::min(dp[i][j], dp[i + 1][j] + 1);
          }
        }
      }
    }

    return dp;
  }
};

class Solution {
public:
  vector<vector<int>> updateMatrix(vector<vector<int>> &grid) {
    int m = grid.size();
    int n = grid[0].size();
    // {x, y} , d
    // BFS 解法：最好带上坐标和当前的最短距离
    queue<pair<pair<int, int>, int>> q;

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == 0) {
          q.push({{i, j}, 0});
        } else {
          grid[i][j] = 10e5;
        }
      }
    }
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

    while (!q.empty()) {
      auto [pos, d] = q.front();
      q.pop();
      int x = pos.first;
      int y = pos.second;
      for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && ny >= 0 && nx < m && ny < n && grid[nx][ny] >= d + 1) {
          grid[nx][ny] = min(grid[nx][ny], d + 1);
          q.push({{nx, ny}, d + 1});
        }
      }
    }

    return grid;
  }
};