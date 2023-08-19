// leetcode 378
// Kth Smallest Element in sorted Matrix

// 给定一个有序的矩阵，我们想知道在这个矩阵中最小的k个数
// 每行每列都是有序的
// 假设这个数为target
// 那么对于每行来说, rows(i) <= target的数量 为count[i]
// 那么所有的行的和 count = \sum count[i]
// 这个性质是二分的
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool check(vector<vector<int>>& matrix, int mid, int k) {
        int count = 0;
        for(int i=0; i<matrix.size(); i++) {
            count += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
        }
        return count < k;
    }

    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();

        int l = matrix[0][0];
        int r = matrix[n-1][n-1];
        
        while(l < r) {
            int mid = l + (r - l) / 2;
            if (check(matrix, mid, k)) l = mid + 1;
            else r = mid ;
        }
        
        return l;
    }
};