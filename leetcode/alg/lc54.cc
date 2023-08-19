// leetcode 54
// Spiral Matrix

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        // 如果只有一行的话 直接返回
        if (m == 1) return matrix[0];
        
        //  如果有多行，但是只有一列
        if (n == 1) {
            vector<int> ans;
            for(int i=0; i<m; i++) ans.push_back(matrix[i][0]);
            return ans;
        }
        
        
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};
        
        int start_x = 0;
        int start_y = 0;
        int end_x = matrix.size() - 1;
        int end_y = matrix[0].size() - 1;
        
        vector<int> ans;
        
        int x = 0;
        int y = 0;
        
        ans.push_back(matrix[x][y]);
        int d = 0;
        int counter = 1;
        
        while(counter < matrix.size() * matrix[0].size()) {
            int nx = x + dx[d];
            int ny = y + dy[d];
    
            if (nx == start_x && ny == end_y && d == 0) {
                d = (d + 1) % 4; 
                start_x ++;
            }
            
            if (nx == end_x && ny == end_y && d == 1) {
                d = (d + 1) % 4;
                end_y --;
            }
            
            if (nx == end_x && ny == start_y && d == 2) {
                d = (d + 1) % 4;
                end_x --;
            }
            
            if (nx == start_x && ny == start_y && d == 3) {
                d = (d + 1) % 4;
                start_y ++;
            }
            
            ans.push_back(matrix[nx][ny]);
            x = nx;
            y = ny;
            counter ++;
        }
        
        return ans;
    }
};