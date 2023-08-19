// leetcode 189
// Rotate Array

// Given an integer array nums, rotate the array to the right by k steps, where
// k is non-negative.

// 需要注意的是Rotate具有周期性
// 所以需要mod
class Solution {
public:
  void rotate(vector<int> &nums, int k) {
    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin() + k % nums.size());
    reverse(nums.begin() + k % nums.size(), nums.end());
  }
};