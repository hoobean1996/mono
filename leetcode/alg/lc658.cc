// leetcode 658
// Find k Closest Elements
// 给定一个有序的数组，我们还需要出两个整数k和x
// 我们希望从数组中找到k个数，这k个数离x最近

// 我们尝试考虑一个大小为k+1的窗口，
// 这个时候考虑删去一个元素
// 如果arr[l]离x较远，那么我们肯定考虑删除arr[l]
// 如果arr[r]离x较远，那么我们肯定考虑删除arr[r]
// 如果一样远，我们也考虑删除arr[r]
// 综上：如果arr[l]离x比较远，那么删除arr[l]，否则就删除arr[r]
//
#include <bits/stdc++.h>

using namespace std;

// a 离 b更近的定义如下:
// 1. |a-x| < |b-x|
//   a .. b .. x -> a 更远
//   a .. x .. b -> x - a > b - x a 更远 (l = mid + 1)
//   x .. a .. b -> b 更远 (r = mid - 1)
// 2. |a-x| == |b-x|, and a < b
//   a .. x .. b -> x - a == b - x b更远

class Solution {
public:
  vector<int> findClosestElements(vector<int> &arr, int k, int x) {
    int l = 0;
    int r = arr.size() - k - 1;

    while (l <= r) {
      int mid = l + (r - l) / 2;
      // 这里为什么不是 abs(x - arr[mid]) > abs(x - arr[mid+k])的原因?
      //
      if (x - arr[mid] > arr[mid + k] - x)
        l = mid + 1;
      else
        r = mid - 1;
    }

    return vector<int>(arr.begin() + l, arr.begin() + l + k);
  }
};