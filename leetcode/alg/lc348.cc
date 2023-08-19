// leetcode 348
// Disign Tic-Tac-Toe

// 利用几个状态变量来快速的查询是否获胜
// 将第一个player的操作记为 +1
// 将第二个player的操作记为 -1
// tic-tac-toe就是形成n个连续的就获胜
//  n行
//  n列
//  对角线和反对角线
#include <bits/stdc++.h> 

using namespace std;

class TicTacToe {
public:
    vector<int> rows;
    vector<int> cols;
    int diagonal;
    int antiDiagonal;
    
    TicTacToe(int n) {
        rows = vector<int>(n, 0);
        cols = vector<int>(n, 0);
        diagonal = 0;
        antiDiagonal = 0;
    }
    
    int move(int row, int col, int player) {
        
        int currentPlayer = (player == 1) ? 1 : -1;

        rows[row] += currentPlayer;
        cols[col] += currentPlayer;
        
        if (row == col) diagonal += currentPlayer;
        if (col == (cols.size() - row - 1)) antiDiagonal += currentPlayer;
        
        int n = rows.size();
        
        if (abs(rows[row]) == n || abs(cols[col]) == n || abs(diagonal) == n || abs(antiDiagonal) == n)  return player;
        
        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */