// leetcode 347
// Top K Frequent Elements

// 给定一个数组，我们想要找到其中出现最频繁的k个元素
// 第一种办法是基于heap来实现，我们统计freq和value
// 实现一个以频率作为优先级来进行排序 O(nlogn)
// 第二种办法是先统计频次，然后对于每个元素来说，存在一个唯一映射 f: value ->
// frequency的函数 我们可以在O(n)的时间内找到快速选出k个元素
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  map<int, int> freq;

  int partition(vector<int> &values, int p, int r) {
    int pivot = freq[values[r]];

    int i = p - 1;
    for (int j = p; j < r; j++) {
      if (freq[values[j]] <= pivot) {
        swap(values[++i], values[j]);
      }
    }
    swap(values[++i], values[r]);
    return i;
  }

  vector<int> topKFrequent(vector<int> &nums, int k) {
    vector<int> values;

    for (const int n : nums) {
      if (freq.count(n) == 0) {
        values.push_back(n);
      }
      freq[n]++;
    }

    int l = 0;
    int r = values.size() - 1;
    int K = values.size() - k;
    int ans = -1

              while (l <= r) {
      int mid = partition(values, l, r);
      if (mid == K) {
        ans = mid;
        break;
      } else if (mid < K)
        l = mid + 1;
      else
        r = mid - 1;
    }

    return vector<int>(values.begin() + K, values.end());
  }
};