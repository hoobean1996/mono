// leetcode 695
// Max Are of Island

class Solution {
public:
  int dfs(vector<vector<int>> &grid, int i, int j) {

    // -1 表示访问过了
    if (grid[i][j] == -1)
      return 0;

    // 0 表示不是水域
    if (grid[i][j] == 0) {
      grid[i][j] = -1;
      return 0;
    }

    int sum = 1;
    grid[i][j] = -1;

    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

    for (int k = 0; k < 4; k++) {
      int newi = i + dx[k];
      int newj = j + dy[k];
      if (newi >= 0 && newi < grid.size() && newj >= 0 &&
          newj < grid[0].size()) {
        sum += dfs(grid, newi, newj);
      }
    }

    return sum;
  }

  int maxAreaOfIsland(vector<vector<int>> &grid) {
    int ans = -1;
    for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid[0].size(); j++) {
        if (grid[i][j] != -1) {
          int area = dfs(grid, i, j);
          if (area > ans) {
            ans = area;
          }
        }
      }
    }

    return ans;
  }
};