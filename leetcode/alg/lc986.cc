// leetcode 986
// Interval List Intersections

// 给定两个closed interval 列表
// 由于两个区间列表是成对不相交的，所以这道题是可以用这种方法解决
// 每个列表没有相交的部分，求解两个列表的交集

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> ans;
        
        int i = 0;
        int j = 0;
        
        // 双指针
        // 考虑当前的指向的两个区间
        // 取左端点的最大值和右端点取最最小值
        // 如果该两个值能够构成一个区间，就放入到答案中
        // 然后考虑右侧
        while(i < firstList.size() && j < secondList.size()) {
            int l = max(firstList[i][0], secondList[j][0]);
            int r = min(firstList[i][1], secondList[j][1]);
            
            if (l <= r) ans.push_back({l, r});
            
            // 考虑当前的交集求出来以后，
            // 如果移动到下一个区间
            // 由于end较小的 都已经放到当前的交集中了，所以可以移动较小的那个即可
            if (firstList[i][1] < secondList[j][1]) i ++ ;
            else j ++;
        }
        
        return ans;
    }
};