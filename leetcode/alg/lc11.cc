// leetcode 11
// Container with most water

// 装最多水的容器 使用双指针即可
// 考虑面积的构成 W * H
// 但是由于双指针的W一定是变小的，所以如果我们把H也变小的话，一定会错过更大的面积
// 所以每次移动高度较小的指针即可

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int maxArea(vector<int> &heights) {
    int l = 0;

    int r = heights.size() - 1;

    int s = 0;

    while (l < r) {
      int curS = (r - l) * min(heights[r], heights[l]);
      if (curS > s) {
        s = curS;
      }
      if (heights[l] < heights[r]) {
        l++;
      } else {
        r--;
      }
    }

    return s;
  }
};