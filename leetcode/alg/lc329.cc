// leetcode 329
// Longest Increasing Path in a Matrix

// 矩阵中的最长上升路径
// DFS + Memorialize 
// 由于是递增路径，所以不需要在额外的记录访问过的点，
// 但是由于可能重复访问某条路径，所以我们需要记忆话搜索
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int ans = 0;
    int m;
    int n;
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

    // 添加一个memo来记录矩阵中(x, y)为起点的最大路径长度来减少搜索次数
    // 时间复杂度是 O(mn)
    vector<vector<int>> memo;

    // dfs计算从(x, y)的最长上升路径的长度
    int dfs(vector<vector<int>> &matrix, int x, int y)
    {   
        // 如果已经计算好了，就直接返回结果接口
        if (memo[x][y] != -1) return memo[x][y];

        // 定义dfs返回点结果是x, y为起点的最长递增路径即可
        int ans = 1;

        // 遍历4个方向，同时找到最长的结果
        for (int k = 0; k < 4; k++)
        {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if (nx >= 0 && ny >= 0 && nx < m && ny < n && matrix[nx][ny] > matrix[x][y])
            {
                ans = max(ans, dfs(matrix, nx, ny) + 1);
            }
        }
        // 记录到memo中即可
        memo[x][y] = ans;
        return ans;
    }

    int longestIncreasingPath(vector<vector<int>> &matrix)
    {
        m = matrix.size();
        n = matrix[0].size();
        memo = vector<vector<int>>(201, vector<int>(201, -1));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                ans = max(ans, dfs(matrix, i, j));
            }
        }

        return ans;
    }
};