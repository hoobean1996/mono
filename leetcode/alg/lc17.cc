// leetcode 17
// Letter Combination of a Phone Number
// 电话字母的所有组合
// 是一道典型的backtrack的题目
// 每个数字有几个字母对应
// 给定一个数字串，求解可能的字符串
#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
  unordered_map<char, string> tbl = {{'2', "abc"}, {'3', "def"}, {'4', "ghi"},
                                     {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"},
                                     {'8', "tuv"}, {'9', "wxyz"}};

public:
  // backtrack(digitis, cur, path, ans)
  // cur 代表当前的位置
  // path 代表当前的路径
  void backtrack(string digits, int cur, string path, vector<string> &ans) {
    if (cur == digits.length()) {
      ans.push_back(path);
      return;
    }

    char c = digits[cur];
    string letters = tbl[c];

    for (int i = 0; i < letters.length(); i++) {
      backtrack(digits, cur + 1, path + letters[i], ans);
    }
  }

  vector<string> letterCombinations(string digits) {
    if (digits.length() == 0)
      return vector<string>();

    vector<string> ans;

    string path;

    backtrack(digits, 0, path, ans);

    return ans;
  }
};