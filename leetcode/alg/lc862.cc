// leetcode 862
// Shortest Subarray with Sum at least K

// 包含负数的情况下
// 给定一个数组和一个数k，我们想知道在它的子数组中，子数组的和至少为k，
// 最短的那个子数组的长度是多少
// 如果这道题都是正数的话，我们就可以利用双指针解决
// 
// 考虑某种数据结构存储所有的前缀和
// 如果当前的s[index] - s[p] >= k ，那么s[p]也就无需要在存储，因为对于后续的q > index 来说，即使s[q] - s[p] >= K
// p->q的长度大于 p->index的长度，所以这个时候需要丢弃头元素
// 布局为 p .. index .. q  如果s[index] - s[p] >= k的话，那么s[index]是不需要的，因为如果s[q] - s[p] >= k 但是我们要的是更短的数组

// 如果存在p < index, 且s[p] >= s[index], 那么对于后续的q > index, s[q] - s[p] >= k的时候，必然有s[q] - s[index] >= k
// 布局为 p .. index .. q 如果s[p] >= s[index] 
// 所以需要丢弃p
// 综上，性质1需要丢弃头部的元素，性质二需要丢掉尾部的元素
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        // 首先求出这个数组的前缀和数组
        vector<int> prefixSum(n+1, 0);
        for(int i=0; i<n; i++) prefixSum[i+1] = prefixSum[i] + nums[i];
        
        int ans = n + 1;

        // 利用单调队列来实现
        deque<int> q;
        for(int i=0; i<prefixSum.size(); i++) {
            // 维护的是一个单调递增的队列
            // 如果当前的前缀和 <= q.back()的前缀和，就弹出最后一个
            // 如果当前的s[index] <= s[p] 丢掉 p
            while(!q.empty() && prefixSum[i] - prefixSum[q.back()] <= 0) q.pop_back();
            
            // 如果当前的前缀和 减去头元素的前缀和的话 >= k的话
            // 如果当前的 s[index] >= s[q.front()], 弹出第一个
            // 记录答案
            while(!q.empty() && prefixSum[i] - prefixSum[q.front()] >= k) {
                ans = min(ans, i - q.front()); 
                q.pop_front();
            }

            q.push_back(i);
        }
        
        return ans < n + 1 ? ans : - 1;
    }
};