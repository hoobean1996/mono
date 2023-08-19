// leetcode 384
// Shuffle an Array

// 数组洗牌算法
// Fisher–Yates Shuffle
// 核心思想是：
// 从1到n之间选出一个数和最后一个数进行交换
// 然后从1到n-1之间选出一个数和倒数第二个数进行交换
// 实现上就是 i = 0..n-1
// 每次是 i 与 random(i, n)想交换
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  vector<int> _array;
  vector<int> _original;

  Solution(vector<int> &nums) {
    _array = nums;
    _original = _array;
  }

  vector<int> reset() {
    _array = _original;
    return _original;
  }

  // 得到一个指定范围的随机数
  int _randRange(int min, int max) { return rand() % (max - min) + min; }

  vector<int> shuffle() {
    for (int i = 0; i < _array.size(); i++) {
      swap(_array[i], _array[_randRange(i, _array.size())]);
    }

    return _array;
  }
};