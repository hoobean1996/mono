// leetcode 41
// First Missing Positive

// 利用所有的值都应该在下标范围内，
// 我们尝试把每个值val = nums[i] 都放到 i+1的位置上
// 那么对于nums[i]来说，就应该放置到 nums[nums[i] -1]的位置上
// 如果任何不满足条件的情况出现，就break
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  // Fist Missing Positive
  // 我们尝试把所有的数 nums[i] 放置到对应的 nums[i]-1的位置上去
  // val = nums[i]

  void bucket_sort(vector<int> &nums) {
    for (int i = 0; i < nums.size(); i++) {
      // 对于当前的数 nums[i] 正确的位置应该是 nums[i] - 1
      // 但是实际上当前的位置是i
      // nums[i] - 1 = i
      // => nums[i] = i + 1
      // 所以如果nums[i] != i + 1
      // 我们就交换
      // 但是需要考虑 nums[i]的位置不合法,
      //  1. <= 0
      //  2. > n
      //  3. nums[i] == nums[nums[i] - 1] 死循环
      while (nums[i] != i + 1) {
        if (nums[i] <= 0 || nums[i] > nums.size() ||
            nums[i] == nums[nums[i] - 1])
          break;
        swap(nums[i], nums[nums[i] - 1]);
      }
    }
  }

  int firstMissingPositive(vector<int> &nums) {
    bucket_sort(nums);

    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] != i + 1)
        return i + 1;
    }

    return nums.size() + 1;
  }
};