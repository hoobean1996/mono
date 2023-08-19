// leetcode 766
// Toeplitz Matrix

// 拓普立姿矩阵
// 如果每个对角线上的所有的元素值都是相同的，那么就是toeplitz矩阵。
// 我们可以考虑对于任意的 (r,c) 如果 matrix[r][c] != matrix[r-1][c-1] 那么肯定就不是
// 所以遍历完以后，如果没有返回false，就一定是，
// 时间复杂度 MN
// 空间复杂度 1
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        for(int r=0; r<matrix.size(); r++) {
            for(int c=0; c<matrix[0].size(); c++) {
                if (r > 0 && c > 0 && matrix[r-1][c-1] != matrix[r][c]) return false;
            }
        }
        
        return true;
    }
};