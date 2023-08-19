// leetcode 26
// Remove Duplicates from Sorted Array
// 有序数组删除重复元素，是需要保留一个的
// 比如 [1,1,2] -> [1,2]
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return n;
        
        // 定义i是上一个不重复的元素的index
        int i = 0; 
        // j是当前元素的index
        int j = 1;
        
        while(i < j && j < n) {
            // 如果当前元素和上一个元素重复 直接跳过
            while(j < n && nums[j] == nums[i]) j++;
            
            // 将不重复的那个元素放入到下一个i的位置即可
            if (i + 1 < n && j < n) nums[++i] = nums[j++];       
        }
        
        return i + 1;
    }
};