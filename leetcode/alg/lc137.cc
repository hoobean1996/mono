// leetcode 137
// Single Number II

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int singleNumber(vector<int> &nums) {
    int ans = 0;
    for (int i = 0; i < 32; i++) {
      int num = 0;
      for (int j = 0; j < nums.size(); j++) {
        num += (nums[j] >> i & 1);
      }
      ans |= (num % 3) << i;
    }

    return ans;
  }
};