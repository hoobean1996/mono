// leetcode 64
// Minimum Path Sum
// 在一个矩形中，找到一个从左上角到右下角的path，使得path的和最小
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if (i >= 1 && j >= 1) {
                    grid[i][j] += min(grid[i-1][j], grid[i][j-1]);
                    continue;
                }
                if (i >= 1) grid[i][j] += grid[i-1][j];
                if (j >= 1) grid[i][j] += grid[i][j-1];
            }
        }
        
        
        return grid[m-1][n-1];
    }
};