// leetcode 16
// 3Sum Cloest

// 3数之和最接近的数
// 维护一个当前的最大差异值
// 然后利用3数之和的思路去找到所有可能的sum，并记录最大的diff，注意到
// 比较的时候要用到绝对值进行比较

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        int diff = INT_MAX;
        sort(nums.begin(), nums.end());
        
        for(int i=0; i<=n-3; i++) {
            if (i > 0 && nums[i] == nums[i-1]) continue;

            int l = i + 1;
            int r = n - 1;
            while(l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if (sum == target) return target;
                int df = sum - target;
                if (abs(df) < abs(diff)) diff = sum - target;
                if (sum < target) l ++ ;
                else r --;
            }
        }
        
        return target + diff;
    }
};