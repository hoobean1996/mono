// leetcode 84
// Largest Rectangle in Histogram
// 计算面积是在出栈的时候完成的
// 注意在弹出的时候面积 = stack.top() * (i - stack.top-1 - 1)
class Solution {
public:
  int largestRectangleArea(vector<int> &heights) {
    stack<int> sk;
    // 单调递增，放入 -1 确保最终能够全部弹出
    sk.push(-1);
    int ans = 0;

    // 注意到单调栈的处理以后
    // 栈中可能还存在一些递增的元素
    for (int i = 0; i < heights.size(); i++) {
      // 如果当前的高度 小于等于栈顶高度，就需要弹出
      // 意味着我们需要维持一个单调递增的栈
      while (sk.top() != -1 && heights[sk.top()] >= heights[i]) {
        int h = heights[sk.top()];
        sk.pop();
        // [sk.top()] [] [i]
        int w = i - sk.top() - 1;
        ans = max(ans, w * h);
      }
      sk.push(i);
    }

    // 处理递增的元素部分
    while (sk.top() != -1) {
      int h = heights[sk.top()];
      sk.pop();
      // 注意到剩下的元素都是最小的元素，所以heights.size() - sk.top() - 1;
      int w = heights.size() - sk.top() - 1;
      ans = max(ans, h * w);
    }

    return ans;
  }
};