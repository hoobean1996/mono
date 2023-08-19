// leetcode 410
// Split Array Largest Sum

// 1. 动态规划
// 用f[i][j]表示前i个数分成j组的 子数组最大和的最小值
// 对于前i个数分为j个组
//  可以考虑将前k个数组划分为j-1组 => f[k][-1]
// 对于剩下的[k+1..i]来说，他们形成的是第j组
// 两者之间较大的时候当前的分组的最大和

class Solution {
public:
  int splitArray(vector<int> &nums, int m) {
    int n = nums.size();
    vector<vector<long>> f(n + 1, vector<long>(m + 1, INT_MAX));
    vector<long> sub(n + 1, 0); // [0..i]
    for (int i = 0; i < n; i++) {
      sub[i + 1] = sub[i] + nums[i];
    }

    f[0][0] = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        for (int k = 0; k < i; k++) {
          f[i][j] = min(f[i][j], max(f[k][j - 1], sub[i] - sub[k]));
        }
      }
    }
    return f[n][m];
  }
};