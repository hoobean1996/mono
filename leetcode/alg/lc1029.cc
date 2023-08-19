// leetcode 1029
// Two City Scheduling

// 有一个公司计划面试2n个人
// 每个人i 去 A城市和B城市的花费不同 分别为 cost[i][0], cost[i][1]
// 问最小的代价去安排这2n个人，其中n个在A城市，其中n个在B城市

// 第一种解法是基于动态规划
// 定dp[i][j] 代表前i个人，有j个去了A地的最小代价
// 那么对于dp[i][j] 考虑第i个人
// 如果他没有去A地，那么前i-1个人就有j个人去了A地
// 如果他去了A地，那么前i个人就有j-1个人去了A地

// dp[i][j] = min(dp[i-1][j] + cost[i-1][1], dp[i-1][j-1] + cost[i-1][0])
// j = 0的情况，所有人都去B地，dp[i][0] = f[i-1][0] + cost[i-1][1]
// dp[0][0] = 0;
// 答案是 dp[n][n/2] n为总人数
// 上面的答案是 O(n^2)
#include <bits/stdc++.h>

using namespace std;

// 第二种是基于贪心算法
// 不妨假设所有的人都去了A地，那么此时地总代价就是sum(cost[i][0]) 
// 然后我们要选择n/2移动到B地，对于每个人移动的代价为 cost[i][1] - cost[i][0]
// 为了要总代价最低，我们要选择移动代价最小的n/2个人去
// 所以我们可以按照 cost[i][1] - cost[i][0] 来排序即可 升序排列的话
// 前n个人就应该去B 后n个人就应该去A即可

class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        // 
        sort(costs.begin(), costs.end(), [](const vector<int>& o1, const vector<int>& o2){
            return (o1[1] - o1[0] < o2[1] - o2[0]); 
        }); 
        
        int total = 0;
        int n = costs.size() / 2;
        
        for(int i=0; i<n; i++) total += (costs[i][1] + costs[i+n][0]);
        
        return total;
    }
};