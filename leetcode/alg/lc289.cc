// leetcode 289
// Life Game
// 生命游戏

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int check(vector<vector<int>> old, int i, int j, int m, int n) {
        int dx[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
        int dy[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };

        int sum = 0;
        for (int k = 0; k < 8; k++) {
            int x = i + dx[k];
            int y = j + dy[k];

            if (x >= 0 && x < m && y >= 0 && y < n) {
                sum += old[x][y] == 1;
            }
        }
        if (old[i][j] == 1) {
            if (sum >= 2 && sum <= 3) return 1;
            return 0;
        }
        else {
            if (sum == 3) return 1;
            return 0;
        }
    }

    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> old = board;

        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                board[i][j] = check(old, i, j, m, n);
            }
        }
    }
};