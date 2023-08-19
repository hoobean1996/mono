// leetcode 265
// Paint House II


// 粉刷房子
// 有一排房子，一共有n个
// 每个房子可以被粉刷成k个颜色之一
// 每种颜色的成本是不一样的
// 同时相邻的两个房子不能刷同样的颜色
// 问把所有房子按条件粉刷的最小成本是多少

// 朴素的DP
// The Total time Complexity O(n)
// The Total space Complexity O(1) (Update in place)

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    const int INF = 0x3f3f;
    
    int minCostII(vector<vector<int>>& costs) {
        if (costs.size() == 0) return 0;
        

        // 房子的数量
        int n = costs.size();

        // 颜色数量
        int k = costs[0].size();
        
        
        for(int house=1; house<n; house++) {
            
            for(int color=0; color<k; color++) {

                // 考虑当前房子的颜色 和 前面一个房子的颜色
                // _min = min(_min, costs[house-1][prevColor])
                // 从而确定和前面一个房子的不同颜色的最小成本
                int _min = INF;
                for(int prevColor=0; prevColor<k; prevColor++) {
                    if (color == prevColor) continue;
                    _min = min(_min, costs[house-1][prevColor]);
                }
                costs[house][color] += _min;
            }
        }
        
        int _min = INF;
        for(int c: costs[n-1]) _min = min(_min, c);
        return _min;
    }
};

// 最优方法
// The total time complexity O(n*k)
// 复用costs数组
// 定义dp[i][j] 是把第i个房子涂成j颜色的时候的花费
// 那么我们的答案应该就是dp[n][:]里面的最小值
// 
// 状态转移：
// dp[i][j] = min(dp[i-1][c] + cost[i][j]) (c!=j) 两个颜色不能相同
// 未优化的版本是我们通过循环来寻找该c
// 但是实际上我们可以维护c
class Solution {
public:
    const int INF = 0x3f3f;
    
    int minCostII(vector<vector<int>>& costs) {
        if (costs.size() == 0) return 0;
        
        int n = costs.size();
        int k = costs[0].size();
        
        for(int house=1; house<n; house++) {
            // minColor 和 secondMinColor 是house-1中的最小值的颜色
            int minColor = -1;
            int secondMinColor = -1;
            
            // O(n) 寻找house-1的最小值和次最小值
            for(int color=0; color<k; color ++) {
                int cost = costs[house-1][color];
                // 1.未找到最小的
                // 2.cost比最小的还要小
                // 更新最小值
                if (minColor == -1 || cost < costs[house-1][minColor]) {
                    secondMinColor = minColor;
                    minColor = color;
                }
                // 1.未找到次最小的
                // 2.cost比次最小的还要小
                // 更新次最小值
                else if (secondMinColor == -1 || cost < costs[house-1][secondMinColor]) secondMinColor = color;
            }
            
            // O(n) 和最小颜色相同的时候，用次最小的颜色
            // 其他情况都用最小的
            for(int color=0; color<k; color ++) {
                if (color == minColor) {
                    costs[house][color] += costs[house - 1][secondMinColor];
                }
                else costs[house][color] += costs[house-1][minColor];
            }
        }
        
        int _min = INF;
        for(const int c: costs[n-1]) _min = min(_min, c);
        
        return _min;
    }
};