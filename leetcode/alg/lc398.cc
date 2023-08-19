// leetcode 398
// Random Pick Index

// 给定一个数组，我们希望每次pick一个值的时候，等概率从所有相同值里面，选出一个下标
// 本质上还是reservoir sampling
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> _nums;
    
    Solution(vector<int>& nums) {
        this->_nums = nums;
    }
    
    // pick
    // 初始化count为1
    // 然后每次遇到给定的元素的话，
    // 用 rand() % count == 0 来有几率大替换到当前的chosenIndex
    // 即可
    int pick(int target) {
        int n = _nums.size();
        int count = 1;
        int chosenIndex = 0;
        
        for(int i=0; i<n; i++) {
            if (_nums[i] == target) {
                // 每次1/count的几率替换到该元素
                if (rand() % count == 0) chosenIndex = i;
                count ++;
            }
        }
        
        return chosenIndex;
    }
};
/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */