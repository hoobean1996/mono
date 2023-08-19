// leetcode 973
// K Closest Points to Origin

// 给定N个点(x,y), 我们希望找到离原点最近的K个点
// 考虑一个简单的问题，找到数组中的k个最小的数，这个是我们基于partition in QuickSort在O(n)完成的
// 考虑到每个点到原点的距离可以映射到一个实数，所以我们就可以在O(n)完成这个问题

// 离原点最近的k个点
// 1. QuickSelect O(N) + O(1)空间复杂度

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // square 能够把一个点映射到一个整数
    int square(vector<int>& point) {
        return point[0] * point[0] + point[1] * point[1];
    }
    
    // partition的实现
    int partition(vector<vector<int>>& points, int l, int r) {
        int pivot = square(points[r]);

        int i = l - 1;
        for(int j=l; j<r; j++) {
            if (square(points[j]) <= pivot) {
                swap(points[++i], points[j]);
            }
        }

        swap(points[++i], points[r]);
        return i;
    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int l = 0;
        int r = points.size() - 1;
        while(l <= r) {
            int p = partition(points, l, r);
            if (p == k) break;
            else if (p < k) l = p + 1;
            else if (p > k) r = p - 1;
        }

        return vector<vector<int>>(points.begin(), points.begin() + k);
    }
};