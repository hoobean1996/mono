// leetcode 215
// Kth Largest Element in an Array

#include <bits/stdc++.h>

using namespace std;

int partition(vector<int> &nums, int p, int r) {
  int pivot = nums[r];

  // i指向的是比pivot小的指针
  // 一开始是-1
  // 如果全部都比pivot大，那么就只有j指针移动
  int i = p - 1;
  // 需要注意 最后一个元素不用考虑
  for (int j = p; j < r; j++) {
    // 如果某个j比pivot小，那么就交换
    if (nums[j] <= pivot) {
      swap(nums[++i], nums[j]);
    }
  }

  swap(nums[++i], nums[r]);
  return i;
}

int findKthLargest(vector<int> &nums, int k) {
  int l = 0;
  int r = nums.size() - 1;
  int ans = -1;
  // 第k大转换为第K小
  int K = nums.size() - k;

  while (l <= r) {
    int mid = partition(nums, l, r);
    if (mid == K) {
      ans = nums[mid];
      break;
    } else if (mid < K)
      l = mid + 1;
    else
      r = mid - 1;
  }

  return ans;
}