// leetcode 912
// sort an array
// 给一个数组排序，就用归并排序即可
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void ms(vector<int>& nums, int l, int r) {
        if (l >= r) return;
        
        int m = (l + r) / 2;
        
        ms(nums, l, m);
        ms(nums, m+1, r);
        
        vector<int> tmp;
        
        int i = l;
        int j = m+1;
        
        while(i<=m && j<=r) {
            if (nums[i] < nums[j]) {
                tmp.push_back(nums[i++]);
            } else {
                tmp.push_back(nums[j++]);
            }
        }
        
        while(i <= m) tmp.push_back(nums[i++]);
        
        while(j <= r) tmp.push_back(nums[j++]);
        
        int k = l;
        for(int i=0; i<tmp.size(); i++)
            nums[k++] = tmp[i];
    }
    
    vector<int> sortArray(vector<int>& nums) {
        ms(nums, 0, nums.size()-1);
        return nums;
    }
};