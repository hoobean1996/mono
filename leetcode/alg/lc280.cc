// leetcode 280
// wiggle sort

// Wiggle Sort I
// nums[0] <= nums[1] >= nums[2] <= nums[3]
// 我们就直接遍历数组，如果不满足这个条件 就交换即可
// 这道题由于允许=，所以直接交换就可以了 
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        bool inc = true;
        
        for(int i=0; i<nums.size()-1; i++) {
            if (inc && nums[i+1] < nums[i]) swap(nums[i], nums[i+1]);
            if (!inc && nums[i+1] > nums[i]) swap(nums[i], nums[i+1]);
            inc = !inc;
        }
    }
};