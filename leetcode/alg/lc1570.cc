// leetcode 1570
// Dot Product of Two Sparse Vectors
// 如何高效的求解两个稀疏矩阵的点积

#include <bits/stdc++.h>

using namespace std;

// 考虑把每个稀疏矩阵转换为一个数组，其中数组的每个元素都是(index, value)
// 并且只需要统计不为0的元素
// 这样的话，我们可以O(n)构造这个稀疏矩阵
// 在求点积的时候，我们利用双指针来计算，这样我们就只需要O(L1+
// L2)的复杂度得到点积 其中L1, L2
// 3. 使用Index-Value pair
// 计算dotProduct O(L1 + L2)
class SparseVector {
public:
  vector<pair<int, int>> pairs;

  SparseVector(vector<int> &nums) {
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] != 0) {
        pairs.push_back({i, nums[i]});
      }
    }
  }

  // Return the dotProduct of two sparse vectors
  int dotProduct(SparseVector &vec) {
    int ans = 0;
    int p = 0;
    int q = 0;

    while (p < pairs.size() && q < vec.pairs.size()) {
      if (pairs[p].first == vec.pairs[q].first) {
        ans += pairs[p].second * vec.pairs[q].second;
        p++;
        q++;
      } else if (pairs[p].first < vec.pairs[q].first)
        p++;
      else
        q++;
    }

    return ans;
  }
};