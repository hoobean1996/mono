// leetcode 240

// Search a 2D matrix II 

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if (matrix.size() == 0) return false;

    int row = matrix.size();

    int col = matrix[0].size();

    // 检测左下角的元素
    int i = row - 1;

    int j = 0;

    while(i >= 0 && j < col) {
        if (matrix[i][j] == target) return true;
        else if (matrix[i][j] < target) j ++;
        else if (matrix[i][j] > target) i --;        
    }

    return false;
}