// leetcode 135
// Candy
// 分糖果

// 1. 每个孩子至少一个糖果
// 2. 分数高的至少要多一个

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int candy(vector<int> &ratings)
    {
        // 首先我们创建一个candies数组，并且全部分配一个糖
        vector<int> candies(ratings.size(), 1);

        // 从左到右，从第二个孩子开始
        for (int i = 1; i < ratings.size(); i++)
        {
            // 分数高的 多分一个糖
            if (ratings[i] > ratings[i - 1])
                candies[i] = candies[i - 1] + 1;
        }

        // 从右到左，从第二个孩子开始
        for (int i = ratings.size() - 2; i >= 0; i--)
        {
            // 分数高的，并且candy不够才需要多分一个糖
            if (ratings[i] > ratings[i + 1] && candies[i] <= candies[i + 1])
                candies[i] = candies[i + 1] + 1;
        }

        return accumulate(candies.begin(), candies.end(), 0);
    }
};