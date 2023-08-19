// leetcode 739
// Daily Temperatures

// 给定一组温度，我们想对于每天的温度，你需要等待多少天才能得到一个更高的温度
// [73,74,75,71,69,72,76,73]
// [1,1,4,2,1,1,0,0]

// 我们的思路还是利用单调栈，维护一个单调递减的栈
// 如果遇到了一个更高的温度，就可以把比他小的全部弹出，并记录时间差值即可
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  vector<int> dailyTemperatures(vector<int> &temperatures) {
    stack<int> sk;

    vector<int> ans(temperatures.size(), 0);

    for (int i = 0; i < temperatures.size(); i++) {
      while (!sk.empty() && temperatures[i] > temperatures[sk.top()]) {
        ans[sk.top()] = i - sk.top();
        sk.pop();
      }
      sk.push(i);
    }

    while (!sk.empty()) {
      ans[sk.top()] = 0;
      sk.pop();
    }

    return ans;
  }
};

class Solution {
public:
  // 定义ans是代表需要等几天才有更高的温度
  // 从右往左扫描，并维护当前的最大值
  // 如果某天的温度比最大值小，首先尝试下一天的温度做比较
  // 如果 temperatures[i + days] 还是比今天的温度小的话，dasy += ans[i+days]
  // 因为ans[i+days]是代表那天还要等多少天才能有更高的温度
  // 利用这种可以优化到O(1)的空间复杂度
  vector<int> dailyTemperatures(vector<int> &temperatures) {
    int n = temperatures.size();
    int hottest = 0;
    vector<int> ans(n);

    for (int i = n - 1; i >= 0; i--) {
      int curTemp = temperatures[i];
      if (curTemp >= hottest) {
        hottest = curTemp;
        continue;
      }

      int days = 1;
      while (temperatures[i + days] <= curTemp)
        days += ans[i + days];
      ans[i] = days;
    }

    return ans;
  }
};