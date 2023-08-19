// leetcode 200
// Number of Islands

// 求解岛屿的数量
// 直接DFS即可，在DFS的时候把1变为0
// 能够调用几次DFS就有几座岛屿

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

    void dfs(vector<vector<char>> &grid, int x, int y)
    {
        grid[x][y] = '0';

        for (int k = 0; k < 4; k++)
        {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if (nx >= 0 && ny >= 0 && nx < grid.size() && ny < grid[0].size() && grid[nx][ny] == '1')
            {
                dfs(grid, nx, ny);
            }
        }
    }

    int numIslands(vector<vector<char>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == '1')
                {
                    dfs(grid, i, j);
                    ans++;
                }
            }
        }

        return ans;
    }
};