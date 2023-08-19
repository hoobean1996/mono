// leetcode 496
// Next Greater Element I
#include <bits/stdc++.h>

using namespace std;
// 利用单调栈 + hashmap实现，单调栈在弹出的时候记录到hashmap

class Solution {
public:
  vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2) {
    stack<int> sk;

    unordered_map<int, int> m;

    for (int i = 0; i < nums2.size(); i++) {
      while (!sk.empty() && nums2[i] > sk.top()) {
        m[sk.top()] = nums2[i];
        sk.pop();
      }
      sk.push(nums2[i]);
    }

    while (!sk.empty()) {
      m[sk.top()] = -1;
      sk.pop();
    }

    vector<int> ans(nums1.size(), 0);

    for (int i = 0; i < nums1.size(); i++)
      ans[i] = m[nums1[i]];

    return ans;
  }
};