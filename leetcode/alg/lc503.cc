// leetcode 503
// Next Greater Element II

#include <bits/stdc++.h>

using namespace std;
// 利用模运算来完成循环遍历
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> ans(nums.size(), -1);
        stack<int> sk;
        int n = nums.size();
        
        // 考虑模运算来访问前面的元素
        for(int i=0; i<2*n; i++) {
            while(!sk.empty() && nums[sk.top()] < nums[i%n]) {
                ans[sk.top()] = nums[i%n];
                sk.pop();
            }
            // 只有前n个元素需要答案
            if (i < n) sk.push(i);
        }
        
        return ans;
    }
};