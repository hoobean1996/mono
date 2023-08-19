// leetcode 37
// Next Permutation
#include <bits/stdc++.h>

using namespace std;

// 首先需要注意到
// 递降数组是没有next permutation的
// 所有从右往左找到递增的部分记为 i i+1
// 然后在从右往左找到第一个大于 i的位置
// 交换i .. j
// 然后由于 i+1之后的都是逆序，我们我们需要reverse一下即可
void nextPermutation(vector<int> &nums) {
  if (nums.size() == 1)
    return;

  int i = nums.size() - 2;

  while (i >= 0 && nums[i + 1] <= nums[i])
    i--;

  if (i < 0) {
    reverse(nums.begin(), nums.end());
  }

  int j = nums.size() - 1;
  while (j >= i + 1 && nums[j] <= nums[i])
    j--;

  swap(nums[i], nums[j]);

  reverse(nums.begin() + i + 1, nums.end());
}