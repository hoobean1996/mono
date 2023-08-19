// leetcode 1428
// Lestmost Column with at least a One
// 给定一个矩阵，我们想找到最左边的至少包含一个1的一列
// 矩阵的每一行都是非降序顺序，所以一旦某个位置出现了一个1，那么后面都是1
// 所以我们从右上角开始 只向左边或者下面移动 N + M
// 由于整个矩阵是按行有序的，所以如果当前位置没有出现1的，1只能在后侧
// 如果当前的位置是0的话，那么肯定就需要往下移动
// 如果当前的位置是1的话，那么就可以往左移动

#include <bits/stdc++.h>

using namespace std;

class BinaryMatrix {
private:
    vector<vector<int>> _matrix;
public:
    int get(int row, int col) { return _matrix[row][col]; }
    vector<int> dimensions() { return {}; }
};


class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix& binaryMatrix) {
        int m = binaryMatrix.dimensions()[0];
        int n = binaryMatrix.dimensions()[1];

        int i = 0;
        int j = n - 1;

        while (i < m && j >= 0) {
            // 如果是1的话，往左移动
            if (binaryMatrix.get(i, j) == 1) j--;
            // 如果是0的话，往下移动
            else i++;
        }

        return (j == n - 1) ? -1 : j + 1;
    }
};