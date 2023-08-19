// leetcode 339
// Nested List Weight Sum

// NestedInteger是一个递归类型，它可以是一个单独的数值，
// 也可以是包含多个NestedInteger的列表。
// 我们想要递归的处理这个类型
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int dfs(NestedInteger ni, int level)
    {   
        // 如果是一个数字的话，直接计算
        if (ni.isInteger())
        {
            return ni.getInteger() * level;
        }

        int sum = 0;

        for (int i = 0; i < ni.getList().size(); i++)
        {   
            // 如果本身是一个列表的话，递归的处理即可
            sum += dfs(ni.getList()[i], level + 1);
        }

        return sum;
    }

    int depthSum(vector<NestedInteger> &nestedList)
    {
        int ans = 0;
        for (int i = 0; i < nestedList.size(); i++)
            ans += dfs(nestedList[i], 1);
        return ans;
    }
};