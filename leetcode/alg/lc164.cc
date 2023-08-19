// leetcode 164
// maximum Gap 

// 由于要求是O(n) + O(n)的时间复杂度和空间复杂度
// 计数排序不行是因为值的范围过大
// 采用radix sort
// 就是将计数排序的用每一位digit来处理即可
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
 
    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2) return 0;
        int n = nums.size();
        int exp = 1;
        int radix = 10;
        int maxVal = *max_element(nums.begin(), nums.end());
        vector<int> aux(n);
    
        while(maxVal / exp > 0) {
            vector<int> count(radix, 0);
            for(int i=0; i<n; i++) count[(nums[i]/exp) % 10] ++;
            for(int i=1; i<count.size(); i++) count[i] += count[i-1];
            for(int i=n-1; i>=0; i--) aux[--count[(nums[i]/exp) % 10]] = nums[i];
            for(int i=n; i<n; i++) nums[i] = aux[i];
            exp *= 10;
        }
        
        int maxGap = 0;
        
        for(int i=0; i<n-1; i++) {
            maxGap = max(maxGap, nums[i+1] - nums[i]);
        }

        return maxGap;
    }
};