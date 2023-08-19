// leetcode 287
// Find the Duplicate Number
// 给定一个数组，一共包含n+1个数，同时所有的数都在[1,n]区间内
// 只有一个数是重复的，我们希望找到这个重复的数。

// 由于所有的数都是正数，所以可以利用变为负数的方法来去重
// 和Jump Game的某个题是相似的
// 要利用所有的元素都在下标区间中
// 所以我们直接一次遍历，当遇到一个数的时候，把对应的下标的数变为负数，
// 在变为负数之前，先检查是否已经变过负数了，如果是就证明已经重复了

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int dup = -1;
        
        for(int i=0; i<nums.size(); i++) {
            // 当前这个数指向的下标
            int cur = abs(nums[i]);

            // 如果是重复的话，那么已经变为负数
            if (nums[cur] < 0) {
                dup = cur;
                break;
            }
            
            // 把这个下标变为负数
            nums[cur] *= -1;
        }
        
        return dup;
    }
};