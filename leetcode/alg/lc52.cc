// leetcode 52
// N-Queues II

int size;

int backtrack(int row, set<int> diag, set<int> antidiag, set<int> cols) {
    if (row == size) return 1;

    int solutions = 0;

    for(int col = 0; col < size; col ++) {
        int curDiag = row - col;
        int curAntiDiag = row + col;
        if (cols.find(col) != cols.end() ||
            diag.find(curDiag) != diag.end() ||
            antidiag.find(curAntiDiag) != antidiag.end()) continue;

        cols.insert(col);
        diag.insert(curDiag);
        antidiag.insert(curAntiDiag);

        solutions += backtrack(row + 1, diag, antidiag, cols);

        cols.erase(col);
        diag.erase(curDiag);
        antidiag.erase(curAntiDiag);
    }

    return solutions;
}

int totalNQueens(int n) {
    size = n;

    set<int> diag, antidiag, cols;

    return backtrack(0, diag, antidiag, cols);
}