// leetcode 452
// Minimum Number of Arrows to Burst Balloons

// 有一组气球，每个气球的水平方向的投影坐标都是[l, r]
// 我们希望往上射箭，把所有的气球射爆，需要最少的箭是多少
// 这道题其实是区间重叠计数的问题
// 假设我们每个气球都需要射一只箭，那么最大值肯定就是气球的数量
// 如果两个气球有重叠的话，那么我们肯定就可以少射一支箭
// 所以问题就转换成了有多少个重叠的气球
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](vector<int>& a, vector<int>& b){
            return a[1] < b[1];
        });
        
        int total = points.size();
        
        // 排序以后，我们把prev指针指向第一个气球
        int prev = 0;
        int remove = 0;
        
        // 遍历后面的气球，如果当前的气球的开始坐标小于上一个气球的结束坐标
        // 那么移除这个气球
        // 否则更新上一个气球为当前的气球
        for(int i=1; i<points.size(); i ++){
            if(points[i][0] <= points[prev][1]) remove++;
            else prev = i;
        }
        
        return total - remove;
    }
};