// leetcode 46
// permutations

class Solution {
public:
  // visited 用于表示是否访问过的标记
  // temp代表当前的排列
  // ans代表所有的排列
  void dfs(int n, vector<int> &temp, vector<bool> &visited,
           vector<vector<int>> &ans, vector<int> &nums) {
    // 如果当前的排列个数为n，放入答案
    if (temp.size() == n) {
      ans.push_back(temp);
    }

    // 遍历
    for (int i = 0; i < n; i++) {
      // 如果没有访问过
      if (!visited[i]) {
        // 标记为访问过
        visited[i] = true;
        temp.push_back(nums[i]);
        dfs(n, temp, visited, ans, nums);
        temp.pop_back();
        // 撤销访问过
        visited[i] = false;
      }
    }
  }

  vector<vector<int>> permute(vector<int> &nums) {
    int n = nums.size();

    vector<int> temp;
    vector<bool> visited(n, false);
    vector<vector<int>> ans;

    dfs(n, temp, visited, ans, nums);

    return ans;
  }
};