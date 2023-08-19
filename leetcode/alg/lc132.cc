// leetcode 132
// Palindrome Partitioning II

#include <bits/stdc++.h>

using namespace std;

// 将一个字符串划分为多个回文子串的最小切割数
// 复杂度 O(N*2^n)
class Solution {
public:
  vector<vector<int>> memoCuts;
  vector<vector<optional<bool>>> memoPalindrome;

  int minCut(string s) {
    memoCuts = vector<vector<int>>(s.length(), vector<int>(s.length(), -1));
    memoPalindrome = vector<vector<optional<bool>>>(
        s.length(), vector<optional<bool>>(s.length(), nullopt));
    return findMinCut(s, 0, s.length() - 1, s.length() - 1);
  }

  // memoCuts[start][end] -> s[start..end]的最小切割数
  // s 字符串s
  // start 当前的子串起始位置
  // end 当前的子串终止
  // findMinCut 返回当前的start..end子串需要的切割数
  int findMinCut(string &s, int start, int end, int minCut) {
    // 如果是单个字符
    // 或者start..end本身就是回文串，那么直接返回，不需要切割
    if (start == end || valid(s, start, end))
      return 0;

    // 如果之前已经有结果了，直接返回
    if (memoCuts[start][end] != -1)
      return memoCuts[start][end];

    // 枚举不同长度的子串，
    for (int i = start; i <= end; i++) {
      if (valid(s, start, i)) {
        minCut = min(minCut, 1 + findMinCut(s, i + 1, end, minCut));
      }
    }
    // 记录当前的切割数量
    memoCuts[start][end] = minCut;
    return minCut;
  }

  bool valid(string &s, int start, int end) {
    if (start >= end)
      return true;

    // std::nullopt is a constant of type std::nullopt_t that is used to
    // indicate optional type with uninitialized state.
    if (memoPalindrome[start][end] != nullopt)
      return (memoPalindrome[start][end] == true);

    memoPalindrome[start][end] =
        (s[start] == s[end] && valid(s, start + 1, end - 1));

    return (memoPalindrome[start][end] == true);
  }
};

// 基于Expand Around the Center + Dynamic Programming

// 考虑s的字串 [i..j]
// 如果s是回文串的话，s[i-1] = s[j+1]的时候，s[i-1..j+1]也是回文串
// isPalindrome(i, j) = true, if s[i] == s[j] and isPalindrome(i+1, j-1) else
// false O(N^2)
class Solution {
public:
  int minCut(string s) {
    // dp[i]设为将s[0..i]切分为若干回文串的最小切割数
    // 那么对于dp[i+1], 我们需要枚举 j in [1..i]的所有点作为可能的切割点
    // 取这些分割点中最小的分割次数

    // dp[i] =
    //  if isPalindrome(0, i) , then 0
    //  if j in [1..i], isPalindrome(j,i) then min(dp[i], dp[j-1] + 1)
    //  otherwise i
    // 所以我们初始化为i
    vector<int> dp(s.length(), 0);

    for (int i = 1; i < s.length(); i++)
      dp[i] = i;

    for (int mid = 0; mid < s.length(); mid++) {
      findMinCuts(mid, mid, dp, s);
      findMinCuts(mid - 1, mid, dp, s);
    }

    return dp[s.length() - 1];
  }

  void findMinCuts(int start, int end, vector<int> &dp, string s) {
    for (int l = start, r = end; l >= 0 && r < s.length() && s[l] == s[r];
         l--, r++) {
      int newCut = l == 0 ? 0 : dp[l - 1] + 1;
      dp[r] = min(dp[r], newCut);
    }
  }
};