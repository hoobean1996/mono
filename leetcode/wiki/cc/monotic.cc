// 单调栈主要用于解决 下一个更大的元素问题
// 单调栈主要的特点在于弹出的时候
// 对于弹出的那个元素来说，当前元素就是它的NGE

void nge() {
  stack<int> s;

  for (int i = 1; i <= n; i++) {
    while (!s.empty() && nums[s.top()] < nums[i]) {
      ans[s.top()] = i;
      s.pop();
    }
  }
}