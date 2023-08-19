// leetcode 77
// combination
// 从n个数中选择k个数组合

class Solution {
public:
  void dfs(int n, int cur, int k, vector<int> &temp, vector<vector<int>> &ans) {
    // 如果已经到达k个数，添加答案
    if (temp.size() == k) {
      ans.push_back(temp);
    }

    // 总是从cur + 1开始选择
    for (int i = cur + 1; i <= n; i++) {
      temp.push_back(i);
      dfs(n, i, k, temp, ans);
      temp.pop_back();
    }
  }

  vector<vector<int>> combine(int n, int k) {

    vector<vector<int>> ans;

    vector<int> temp;

    dfs(n, 0, k, temp, ans);

    return ans;
  }
};