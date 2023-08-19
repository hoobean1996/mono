// leetcode 239

// Sliding Window Maximum
// 滑动窗口最大值
// 给定一个数组，和一个窗口大小
// 我们希望找到每个窗口的最大值

// 维护一个单调递减的栈，当遇到一个更大的值的时候，就开始从后面弹出
// 还需要考虑如果队列的长度 > k，还需要弹出头元素
// deque<int> q
// q.pop_back() q.pop_front()
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  vector<int> maxSlidingWindow(vector<int> &nums, int k) {
    vector<int> ans;

    // deque means double end queue
    deque<int> q;

    for (int i = 0; i < nums.size(); i++) {
      // Process all numbers that valate the property
      while (!q.empty() && nums[i] > nums[q.back()])
        q.pop_back();

      // Push the new number's index
      q.push_back(i);

      // if length > k, then we need to pop front
      if (!q.empty() && i - q.front() > k - 1)
        q.pop_front();

      // The max number only occurs when the index >= k-1
      if (i >= k - 1)
        ans.push_back(nums[q.front()]);
    }

    return ans;
  }
};