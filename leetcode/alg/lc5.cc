// leetcode 5
// Longest Palindromic Substring
// 返回一个字符串中的最长回文子串

// 最长回文子串
// Solution 1: manacher算法
// 首先在字符串中插入#来让问题变得简单
// 然后调用manacher算法计算得到d1数组
// 然后在d1数组中找到最大的值和下标

// 为了快速计算，我们维护一个最右的子回文串的边界 [l, r]
// 初始化为(0, -1)
// 假设我们要计算下一个位置i的d1，而且之前的已经计算完毕
// 1. 如果i位于当前的[l,r]之外, i > r => 我们调用朴素的算法，扩展即可
//   不断的检查i-d1[i] .. i+d1[i]是否相同即可
// 2. i <= [l, r] 即 i在该范围内
//      假设i的对称位置 j = l + (r - i) 如果j - d1[i] + 1 <= l 超过了范围
//      我们就应该截断d1[i] = r - i 然后朴素的扩展即可
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  // 计算字符串的d1数组
  // 注意到 l = 0, r = -1
  // l + (r-i)是在当前回文串种i的对称位置
  vector<int> manacher(string s) {
    int n = s.length();

    vector<int> d1(n);
    // 初始化 [0, -1]
    int l = 0;
    int r = -1;

    // 开始处理整个字符串，
    for (int i = 0; i < n; i++) {
      // 令k是当前的d1[i]的初始化的值
      // 如果i > r -> k = 1
      // 如果i <= r -> k = min(d1[l+r-i], r-i+1) 取较小的值
      int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
      // 然后利用朴素算法不断的扩展该位置的值
      // i-k >= 0
      // i+k < n
      // 同时 s[i-k] == s[i+k]的话， k++
      while (0 <= i - k && i + k < n && s[i - k] == s[i + k])
        k++;
      // 经过上面的计算以后，d1[i] = k--
      d1[i] = k--;
      // 同时根据 i + k是否大于r来更新r和l
      // 注意到k是半径
      // 所以 i + k是当前的r
      //     i - k是当前的l
      if (i + k > r) {
        l = i - k;
        r = i + k;
      }
    }

    return d1;
  }

  // 求最长的回文子串
  // 1. 将原字符串进行预处理，在每个位置插入一个 #
  // 2. 调用manacher算法，计算出每个位置的d1的值
  // 3. 我们遍历整个数组，可以找到最大的d1的值，和该位置的下标
  // 4. 然后利用对称的位置从 idx - maxD1 + 1 ... idx + maxD1 - 1遍历，去除掉
  // #的字符即可
  string longestPalindrome(string s) {
    string t = "#";
    for (const char c : s) {
      t += c;
      t += "#";
    }

    vector<int> d1 = manacher(t);

    int maxD1 = *max_element(d1.begin(), d1.end());
    int maxD1Index = distance(d1.begin(), maxD1);

    string res;
    for (int i = maxD1Index - maxD1 + 1; i < maxD1Index + maxD1 - 1; i++) {
      if (t[i] != '#')
        res += t[i];
    }

    return res;
  }
};