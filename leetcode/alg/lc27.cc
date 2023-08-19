// leetcode 27 
// Remove Element

// 给定一个数组，我们希望在这个数组中删除指定的元素，返回删除以后的数组长度.
// 考虑[0, i]是不包含该元素的有效区间
// 初始化 i = -1, 空区间
// 遍历数组，当遇到的元素是需要删除的元素的时候，直接跳过
// 否则nums[++i] = nums[j++] 拷贝过去
// 最后返回 i + 1的长度
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = -1;
        
        for(int j=0; j<nums.size(); j++) {
            if (nums[j] != val) nums[++i] = nums[j];
        }
        
        return i + 1;
    }
};