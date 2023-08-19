// leetcode 296
// Best Meeting Point
// 最好会议点

// 给定一个m*n的矩阵
// 1 代表朋友的住所
// 求一个相遇点，使得整体的距离最小（到各个房子的距离)

// 曼哈顿距离的性质 可以两个维度直接相加
// 考虑一维的曼哈顿距离case

// 最重要的点就是选择中位数，并且两个维度是独立的
// 1. 单独收集所有的点坐标
// 2. 排序
// 3. 分别用rows的中位数和cols的中位数来计算最大距离
// 求解中位数的部分可以用partition来优化

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

int minTotalDistance(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = m == 0 ? 0 : grid[0].size();

    vector<int> rows, cols;

    int res = 0;

    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            if (grid[i][j] != 1) continue;
            rows.push_back(i);
            cols.push_back(j);
        }
    }

    sort(rows.begin(), rows.end());

    int row = rows[rows.size()/2];

    sort(cols.begin(), cols.end());

    int col = cols[cols.size()/2];

    return min1d(rows, row) + min1d(cols, col);
}

int min1d(vector<int> points, int origin) {
    int dist = 0;
    for(int i=0; i<points.size(); i++) dist += abs(points[i] - origin);
    return dist;
}
};