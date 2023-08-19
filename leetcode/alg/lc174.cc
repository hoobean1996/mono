// leetcode 174
// Dungeon Game 
// 地牢游戏

// 感觉二分也是可以的

// 通常情况下，使用动态规划是知道初始条件的，但是这道题是需要我们
// 求解初始条件。
// 定义dp[i][j]是从(i,j)走到公主所在的格子，需要的最少生命值
// 状态转移方程: dp[i][j] = max(1, max(dp[i+1][j], dp[i][j+1]) - dungeon[i][j]);

#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    int inf = 0x3f3f;
    vector<vector<int>> dp;
    int rows;
    int cols;
    
    int getMinHp(int curCell, int nextRow, int nextCol) {
        if (nextRow >= rows || nextCol >= cols) return inf;
        int nextCell = dp[nextRow][nextCol];
        return max(1, nextCell - curCell);
    }
    
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        rows = dungeon.size();
        cols = dungeon[0].size();
        dp = vector<vector<int>>(rows, vector<int>(cols, inf));
        
        // 观察这个DP表生成的顺序，可以利用滚动数组优化到O(N)的空间
        for(int i=rows-1; i>=0; i--) {
            for(int j=cols-1; j>=0; j--) {
                // 考虑当前位置的值
                int curCell = dungeon[i][j];
                int minHp = inf;

                // 先看该节点的下一个位置需要多少生命值
                int rightHp = getMinHp(curCell, i, j + 1);
                int downHp = getMinHp(curCell, i + 1, j); 
                int nextHp = min(rightHp, downHp);

                // 如果是一个有效的值，那么该位置至少需要那么多                
                if (nextHp != inf) minHp = nextHp;
                // 如果是一个无效的值
                // 如果是加血的位置就是1即可
                // 如果是扣血的位置就要加上扣血的相反数
                else minHp = curCell >= 0 ? 1 : 1 - curCell;

                dp[i][j] = minHp;
            }
        }
        
        return dp[0][0];
    }
};