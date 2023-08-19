// leetcode 493
// reversed pair
// 求一个数组中的逆序对
// 在Merge的过程中求逆序对即可
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int ans;
    
    void merge(vector<int>& nums, int l, int r) {
        if (l >= r) return;
        
        int mid = (l + r) >> 1;
        
        merge(nums, l, mid);
        merge(nums, mid+1, r);
        
        int i = l;
        int j = mid + 1;
        int k = 0;
        
        while(i <= mid && j <= r) {
            long long x = nums[i];
            long long y = nums[j];
            if (x > 2 * y) {
                ans += mid - i + 1;
                j++;
            } else {
                i ++;
            }
        }
        
        
        i = l;
        j = mid + 1;
        k = 0;
        
        vector<int> t(r-l+1);
        
        while(i <= mid && j <= r) {
            if (nums[i] > nums[j]) {
                t[k++] = nums[j++];
                
            } else {
                t[k++] = nums[i++];
            }
        }
        
        while(i <= mid) t[k++] = nums[i++];
        while(j <= r) t[k++] = nums[j++];
        
        for(int i=l, j=0; i<=r; i++, j++) nums[i] = t[j];
    }
    
    int reversePairs(vector<int>& nums) {
        ans = 0;
        merge(nums, 0, nums.size() - 1);
        return ans;
    }
};
