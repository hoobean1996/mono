// leetcode 56
// Merge Intervals

// 合并区间，按照起始点排序，
// 然后不断的合并两个区间即可
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  vector<vector<int>> merge(vector<vector<int>> &intervals) {
    // 如果只有一个区间，就不用处理了
    if (intervals.size() <= 1) {
      return intervals;
    }
    // [x, y]
    // 按照x坐标进行排序
    sort(
        intervals.begin(), intervals.end(),
        [](const vector<int> &a, const vector<int> &b) { return a[0] < b[0]; });

    // 在合并区间的时候，最重要的是需要考虑前一个区间和当前区间的关系
    vector<vector<int>> ans;
    vector<int> prev = intervals[0];

    for (int i = 1; i < intervals.size(); i++) {
      vector<int> cur = intervals[i];

      // 如果当前区间的x坐标和上一个区间的y坐标重叠了
      // 意味着他们可以合并为一个区间
      if (cur[0] <= prev[1]) {
        prev[1] = max(prev[1], cur[1]);
      } else {
        // 否则的话 更新到prev
        ans.push_back(prev);
        prev = cur;
      }
    }

    // 一定需要记住 最后需要处理prev
    ans.push_back(prev);
    return ans;
  }
};