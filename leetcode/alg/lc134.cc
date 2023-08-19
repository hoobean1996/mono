// leetcode 134
// Gas Station
// 要在O(n)完成是比较难的
// 假设 x->y是不可达的
// j in [x, y)是可达的
// 我们可以利用几个关系证明 j in [x, y): j -> y也是不可达的
// 所以只要不可达的 都可以跳过即可

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int n = gas.size();

        int total_tank = 0;
        int cur_tank = 0;
        int from = 0;

        for (int i = 0; i < n; i++)
        {
            total_tank += gas[i] - cost[i];
            cur_tank += gas[i] - cost[i];
            if (cur_tank < 0)
            {
                from = i + 1;
                cur_tank = 0;
            }
        }

        return total_tank >= 0 ? from : -1;
    }
};