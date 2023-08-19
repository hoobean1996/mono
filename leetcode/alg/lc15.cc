// leetcode 15
// 3Sum

// 3数之和的思路很简单
// 1. 先排序
// 2. 枚举第一个数 0..n-3
// 3. 对于每一个数，都设置双指针，然后进行判断即可
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        
        for(int i=0; i<=n-3; i++) {
            if (i > 0 && nums[i] == nums[i-1]) continue;
            
            int l = i + 1;
            int r = n - 1;
            
            while(l < r) {
                int sum = nums[i] + nums[l] + nums[r];                
                
                if (sum == 0) {
                    ans.push_back({nums[i], nums[l], nums[r]});
                    while(l < r && nums[l] == nums[l+1]) l ++;
                    while(l < r && nums[r] == nums[r-1]) r --;
                    
                    l ++;
                    r --;
                }
                else if (sum < 0) l ++;
                else r --;
            }
        }
        
        return ans;
    }
};