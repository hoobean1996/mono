// leetcode 63
// Unique Path ii

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        if (obstacleGrid[0][0] == 1) return 0;
        
        // 初始化到(0, 0)只有一步
        obstacleGrid[0][0] = 1;
        
        // 初始化第一列
        for(int r=1; r<m; r++) obstacleGrid[r][0] = (obstacleGrid[r][0] == 0 && obstacleGrid[r-1][0] == 1) ? 1: 0;
        
        // 初始化第一行
        for(int c=1; c<n; c++) obstacleGrid[0][c] = (obstacleGrid[0][c] == 0 && obstacleGrid[0][c-1] == 1) ? 1: 0;
        
        for(int i=1; i<m; i++) {
            for(int j=1; j<n; j++) {
                if (obstacleGrid[i][j] == 0) obstacleGrid[i][j] = obstacleGrid[i-1][j] + obstacleGrid[i][j-1];
                else obstacleGrid[i][j] = 0;
            }
        }
        
        return obstacleGrid[m-1][n-1];
    }