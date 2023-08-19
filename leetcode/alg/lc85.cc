// leetcode 85
// Maximal Rectangle
// 最大的矩形
// 我们可以将矩阵转换为heights数组，在利用单调栈求解heights数组中的最大矩形

class Solution {
public:
  int largestRectangleArea(vector<int> &heights) {
    int n = heights.size();
    stack<int> sk;
    sk.push(-1);

    int ans = 0;
    for (int i = 0; i < n; i++) {
      while (sk.top() != -1 && heights[i] < heights[sk.top()]) {
        int h = heights[sk.top()];
        sk.pop();
        int w = i - sk.top() - 1;
        ans = max(ans, w * h);
      }
      sk.push(i);
    }

    while (sk.top() != -1) {
      int h = heights[sk.top()];
      sk.pop();
      int w = n - sk.top() - 1;
      ans = max(ans, w * h);
    }

    return ans;
  }

  int maximalRectangle(vector<vector<char>> &matrix) {
    if (matrix.size() == 0)
      return 0;
    int maxarea = 0;
    vector<int> dp(matrix[0].size(), 0);

    for (int i = 0; i < matrix.size(); i++) {
      for (int j = 0; j < matrix[0].size(); j++) {
        dp[j] = matrix[i][j] == '1' ? dp[j] + 1 : 0;
      }
      maxarea = max(maxarea, largestRectangleArea(dp));
    }

    return maxarea;
  }
};