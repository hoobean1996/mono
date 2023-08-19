// leetcode 300
// 最长递增子序列
// 给定一个数组，我们希望知道在这个数组中的最长递增的子序列的长度是多少

// 由于是需要递增的子序列，所以我们可以定义 dp[i]是以i结尾的递增子序列的长度
// 那么我们就可以从头开始遍历直到i之前的元素，
// 这样的时间复杂度是O(n^2)
// 空间复杂度是O(n)
// 但是如果我们引入贪心策略 + 二分搜索可以把这个问题在O(nlogn)的复杂度解决
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:    
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        
        // 我们需要一个辅助数组来记录当前的递增序列
        // 首先是需要把第一个元素放进去的
        vector<int> b;
        b.push_back(nums[0]);

        // 考虑一个新的元素a[i]
        // 如果a[i]比末尾元素大，那么就继续添加
        // 否则的话，用a[i]替换到b[i]中第一个>=a[i]的元素
        // （基于末尾元素越小，越有可能增加LCS的长度)
        for(int i=1; i<n; i++) {
            if (nums[i] > b.back()) b.push_back(nums[i]);
            else {
                int j = lower_bound(b.begin(), b.end(), nums[i]) - b.begin();
                b[j] = nums[i];
            }
        }
        
        // 这个过程中最大的size就是结果
        return b.size();
    }
};