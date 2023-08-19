// leetcode 18
// 4 Sum

// 4 数之和的话，基本上和3数之和类似
// 1. 先排序
// 2. 利用两重循环 来进行遍历， 然后枚举双指针的可能即可

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> ans;
        if (n <= 3) return ans;
        
        sort(nums.begin(), nums.end());
        
        for(int i=0; i<n-3; i++) {
            if (i && nums[i] == nums[i-1]) continue;
            
            for(int j=i+1; j<n-2; j++) {
                if (j != i + 1 && nums[j] == nums[j-1]) continue;
                int l = j + 1;
                int r = nums.size() - 1;
                int total = target - nums[i] - nums[j];
                while(l < r) {
                    int val = nums[l] + nums[r];
                    if (val == total) {
                        ans.push_back( {nums[i], nums[j], nums[l], nums[r]});
                        l++;
                        r--;

                        while(l < r && nums[l] == nums[l-1]) l++;
                        while(l < r && nums[r] == nums[r+1]) r--;
                    } 
                    else if (val < total) l ++;
                    else if (val > total) r --;
                }
            }
        }
        return ans;
    }
};