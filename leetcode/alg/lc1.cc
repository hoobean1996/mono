// leetcode 1
// Two Sum

// 两数之和
// 利用hash记录当前已有的值，当遍历到一个新的值的时候，就check hashmap中的值
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    unordered_map<int, int> m;

    for (int i = 0; i < nums.size(); i++) {
      if (m.find(target - nums[i]) != m.end()) {
        return {i, m[target - nums[i]]};
      }
      m[nums[i]] = i;
    }

    return {-1, -1};
  }
};

// unordered_map  内部元素无序，Key元素需要实现 operator==
// map 底层是通过二叉搜索树（用红黑树实现的）的，需要实现 operator <
/**
    // 迭代器
    begin 返回起始迭代器
    end 返回末尾迭代器
    cbegin => const begin
    cend => const end

    // capacity
    size()
    max_size()
    empty

    // access
    operator[]
    at



*/