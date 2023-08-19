// leetcode 120
// Triangle
// 给定一个三角形的数阵
// 我们想知道从上到下的最小的路径是什么
// 考虑triangle[x][y]是从(x, y) -> 最后一排的最小路径
// 那么答案就是triangle[0][0]

// triangle[i][j] 
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
       if (triangle.size() == 0) return 0;

       for(int i=triangle.size() - 2; i>=0; i--) {
           for(int j=0; j<triangle[i].size(); j++) {
               triangle[i][j] += min(triangle[i+1][j], triangle[i+1][j+1]);
           }
       }

       return triangle[0][0];
    }
};
