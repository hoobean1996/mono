// leetcode 163
// Missing Ranges

// 给定一个区间[low, high] 给一组数
// 我们想知道在这个区间内缺失的整数
// 如果缺失的一个数，就输出一个数
// 如果缺失的几个连续的数，就输出一个区间

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string formatRange(int l, int r) {
        if (l == r) return to_string(l);
        return to_string(l) + "->" + to_string(r);
    }
    
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> ans;
        
        // 定义prev初始化为lower-1
        int prev = lower - 1;

        // 遍历这个数组 
        // 注意 多遍历了一次
        for(int i=0; i<=nums.size(); i++) {
            int cur = i < nums.size() ? nums[i] : upper + 1;
            
            if (prev + 1 <= cur - 1) ans.push_back(formatRange(prev + 1, cur - 1));
            prev = cur;
        }
        
        return ans;
    }
};