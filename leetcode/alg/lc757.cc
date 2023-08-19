// leetcode 757
// Set Intersection Size At Least Two

// 整数区间[a, b]（对于整数）是从到a < b的所有连续整数的集合，包括和。abab

// 求集合 S 的最小大小，使得对于 中的每个整数区间 A intervals，S 与 A 的交集的大小至少为 2。
#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        // 首先按照end升序排序
        // 如果相同的话，按照start降序排序
        sort(intervals.begin(), intervals.end(), [](auto& lhs, auto& rhs) {
            return lhs[1] < rhs[1] || (lhs[1] == rhs[1] && lhs[0] > rhs[0]);
        }); 

        int ans = 0, y0 = -1, y1 = -1; 
        
        for (auto& interval : intervals) {
            int x = interval[0], y = interval[1]; 
            if (y0 < x && x <= y1){
                y0 = y1;
                y1 = y;
                ans ++;
            }
            else if (y1 < x) {
                y0 = y - 1;
                y1 = y;

                ans += 2;
            }
        }
        return ans; 
    }
};