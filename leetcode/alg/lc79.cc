// leetcode 79
// Word Search I
// 在矩阵中的单词搜索，只搜索一个单词
// 我们可以利用dfs来看看

// 思路是一样的，但是很明显这种写法要更简单一点
// 没有必要单独开一个数组来去重，可以将原字符改为 #

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<char>> _board;
    int _rows;
    int _cols;
    
    
    bool exist(vector<vector<char>>& board, string word) {
        _board = board;
        _rows = board.size();
        _cols = board[0].size();
        
        for(int i=0; i<_rows; i++) {
            for(int j=0; j<_cols; j++) {
                if (backtrack(i, j, word, 0)) return true;
            }
        }
        return false;
    }
    
    bool backtrack(int x, int y, string word, int index) {
        if (index >= word.length()) return true;
        if (x < 0 || x == _rows || y < 0 || y == _cols || _board[x][y] != word[index]) return false;
        bool ret = false;
        _board[x][y] = '#';
        
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};
        
        for(int k=0; k<4; k++) {
            ret = backtrack(x + dx[k], y + dy[k], word, index + 1);
            if (ret) break;
        }
        _board[x][y] = word[index];
        return ret;
    }
};