// leetcode 1197
// Minimum Knight Moves
// 在一个无限的棋盘里面，一个骑士在 (0, 0)的位置
// 希望到达 [x, y] 问最少需要多少次移动
// 直接使用BFS是会超时的

// 记忆化 DFS
// 1. 对称性 (x, y), (x, -y), (-x, y), (-x, -y) 的答案是相同的
// 2. 因此我们可以在第一象限搜索 first quadrant
// 3. 基于这样的假设，我们可以降低搜索的范围, 我们从终点开始搜索到原点
// 4. 假设dfs(x, y)是到达 (x, y)的最小移动次数 
// 5. 那么 dfs(x, y) -> min(dfs(x-2, y-1), dfs(x-1, y-2)) + 1
// 时间复杂度是 O(x*y)
// 空间复杂度 O(x*y)

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    unordered_map<string, int> memo;
    
    int dfs(int x, int y) {
        string key = to_string(x) + "," + to_string(y);
        
        if (memo.count(key)) return memo[key];
        
        // 到达原点的时候，答案为0
        if (x + y == 0) return 0;
        // (0, 2) (2, 0) (1, 1)
        // 直接返回答案即可
        else if (x + y == 2) return 2;
        else {
            int ret = min(dfs(abs(x-1), abs(y-2)), dfs(abs(x-2), abs(y-1))) + 1;
            memo[key] = ret;
            return ret;
        }
    }
    
    int minKnightMoves(int x, int y) {
        return dfs(abs(x), abs(y));
    }
};
