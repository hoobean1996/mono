// leetcode 498
// Diagonal Traverse 
// 对角线遍历

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<vector<int>> ans;

        bool reversed = true;
        // i = 0 .. m - 1 + n - 1 
        //   x = 0 .. m
        //     y = 0 .. n
        //       if (x + y == i) 
        for (int i = 0; i <= (mat.size() - 1 + mat[0].size() - 1); i++) {
            vector<int> dig;
            for (int x = 0; x < mat.size(); x++) {
                for (int y = 0; y < mat[0].size(); y++) {
                    if (x + y == i) dig.push_back(mat[x][y]);
                    else continue;
                }
            }
            if (reversed) reverse(dig.begin(), dig.end());
            reversed = !reversed;
            ans.push_back(dig);
        }
        vector<int> _ans;
        for (int i = 0; i < ans.size(); i++) {
            for (int j = 0; j < ans[i].size(); j++) _ans.push_back(ans[i][j]);
        }
        return _ans;
    }
};