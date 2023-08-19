// leetcode 364
// Nested List Weight Sum II
// 这道题定义的计算是定义weight = maxDepth - (the depth for each integer)  + 1
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int _maxDepth = 0;

    int getMaxDepth(NestedInteger ni)
    {
        if (ni.isInteger())
            return 1;

        int maxDepth = 1;
        for (int i = 0; i < ni.getList().size(); i++)
            maxDepth = max(maxDepth, getMaxDepth(ni.getList()[i]) + 1);
        return maxDepth;
    }

    int getWeightSum(NestedInteger ni, int level)
    {
        if (ni.isInteger())
            return (_maxDepth - level + 1) * ni.getInteger();

        int sum = 0;
        for (int i = 0; i < ni.getList().size(); i++)
            sum += getWeightSum(ni.getList()[i], level + 1);
        return sum;
    }

    int depthSumInverse(vector<NestedInteger> &nestedList)
    {
        for (int i = 0; i < nestedList.size(); i++)
        {
            _maxDepth = max(_maxDepth, getMaxDepth(nestedList[i]));
        }
        int ans = 0;
        for (int i = 0; i < nestedList.size(); i++)
            ans += getWeightSum(nestedList[i], 1);
        return ans;
    }
};