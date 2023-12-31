// leetcode 417
// 417. Pacific Atlantic Water Flow

class Solution {
public:
  int dx[4] = {-1, 0, 1, 0};
  int dy[4] = {0, 1, 0, -1};

  vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights) {
    if (heights.empty() || heights[0].empty())
      return {};

    vector<vector<int>> ans;
    int m = heights.size();
    int n = heights[0].size();

    vector<vector<bool>> can_reach_p(m, vector<bool>(n, false));
    vector<vector<bool>> can_reach_a(m, vector<bool>(n, false));

    for (int i = 0; i < m; i++) {
      dfs(heights, can_reach_p, i, 0);
      dfs(heights, can_reach_a, i, n - 1);
    }

    for (int i = 0; i < n; i++) {
      dfs(heights, can_reach_p, 0, i);
      dfs(heights, can_reach_a, m - 1, i);
    }

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (can_reach_p[i][j] && can_reach_a[i][j])
          ans.push_back(vector<int>{i, j});
      }
    }

    return ans;
  }

  void dfs(const vector<vector<int>> &matrix, vector<vector<bool>> &can_reach,
           int r, int c) {
    if (can_reach[r][c])
      return;

    can_reach[r][c] = true;

    for (int k = 0; k < 4; k++) {
      int nx = r + dx[k];
      int ny = c + dy[k];

      if (nx >= 0 && nx < matrix.size() && ny >= 0 && ny < matrix[0].size() &&
          matrix[r][c] <= matrix[nx][ny]) {
        dfs(matrix, can_reach, nx, ny);
      }
    }
  }
};