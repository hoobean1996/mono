// leetcode 253
// Meeting Room II

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  // [s, e] -> (s, e, e-s)
  // 按照开始时间排序
  int minMeetingRooms(vector<vector<int>> &intervals) {
    if (intervals.size() <= 1)
      return intervals.size();

    // 按照会议开始的时间排序
    sort(
        intervals.begin(), intervals.end(),
        [](const vector<int> &a, const vector<int> &b) { return a[0] < b[0]; });

    // 然后依次放入到优先级队列，放入的会议的结束时间
    // 最小堆
    priority_queue<int, vector<int>, greater<int>> pq;

    // 首先放入第一个会议的结束时间
    pq.push(intervals[0][1]);

    for (int i = 1; i < intervals.size(); i++) {
      // 从第二个开始，如果当前的会议的开始时间在上一个会议的结束时间之后，证明他们可以利用同一个会议室
      // 所以就pop
      if (!pq.empty() && pq.top() <= intervals[i][0])
        pq.pop();
      pq.push(intervals[i][1]);
    }

    return pq.size();
  }
};