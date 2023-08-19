// leetcode 47
// permutation ii

class Solution {
public:
  vector<vector<int>> ans;
  int n;
  vector<bool> vis;

  void dfs(vector<int> &temp, vector<int> &nums) {
    if (temp.size() == n) {
      ans.push_back(temp);
    }

    for (int i = 0; i < nums.size(); i++) {
      if (!vis[i]) {
        vis[i] = true;
        temp.push_back(nums[i]);
        dfs(temp, nums);
        temp.pop_back();
        vis[i] = false;
      }
    }
  }

  vector<vector<int>> permuteUnique(vector<int> &nums) {
    n = nums.size();
    vis = vector<bool>(nums.size(), false);

    sort(nums.begin(), nums.end());

    vector<int> temp;

    dfs(temp, nums);

    set<vector<int>> s;
    for (auto x : ans)
      s.insert(x);

    return vector<vector<int>>(s.begin(), s.end());
  }
};