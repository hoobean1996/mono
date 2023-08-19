// leetcode 130
// Surrounded Regions

// 包围的Region
// 这道题是利用从边界开始dfs，
// 每次dfs的时候 所有不为O的 都直接返回，把O改为E
// 在所有的DFS结束之后，把所有的E改为O，O改为X
// 相当于我们要找的是从边界可达的O，然后改为E
// 中间被包围的部分，由于完全被包围，它肯定是不可达的
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int rows = 0;
    int cols = 0;

    void dfs(vector<vector<char>> &board, int row, int col)
    {
        if (board[row][col] != 'O')
            return;

        // 只有在border为O的时候才会处理
        board[row][col] = 'E';
        if (col < cols - 1)
            dfs(board, row, col + 1);
        if (row < rows - 1)
            dfs(board, row + 1, col);
        if (col > 0)
            dfs(board, row, col - 1);
        if (row > 0)
            dfs(board, row - 1, col);
    }

    void solve(vector<vector<char>> &board)
    {
        if (board.size() == 0)
            return;

        rows = board.size();
        cols = board[0].size();

        vector<pair<int, int>> borders;

        for (int r = 0; r < rows; r++)
        {
            borders.push_back({r, 0});
            borders.push_back({r, cols - 1});
        }
        for (int c = 0; c < cols; c++)
        {
            borders.push_back({0, c});
            borders.push_back({rows - 1, c});
        }

        for (const pair<int, int> &p : borders)
            dfs(board, p.first, p.second);

        for (int r = 0; r < rows; r++)
        {
            for (int c = 0; c < cols; c++)
            {
                if (board[r][c] == 'O')
                    board[r][c] = 'X';
                if (board[r][c] == 'E')
                    board[r][c] = 'O';
            }
        }
    }
};