// leetcode 13
// Roman to Integer

// 罗马字符转换为数字
// 由于罗马字符不可能出现歧义，所以我们优先考虑是否能够构成两位的罗马字符
// 如果可以构成两位的罗马字符，那么就 += 对应的数值
// 如果只能构成一位的罗马字符，就 += 对应的数值
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int romanToInt(string s) {
    unordered_map<string, int> tbl{
        {"I", 1},   {"IV", 4},   {"V", 5},   {"IX", 9},  {"X", 10},
        {"XL", 40}, {"L", 50},   {"XC", 90}, {"C", 100}, {"CD", 400},
        {"D", 500}, {"CM", 900}, {"M", 1000}};

    int ans = 0;

    int i = 0;

    while (i <= s.length() - 1) {
      // 如果[i..i+1]可以构成一个数字
      if (i + 1 <= s.length() - 1) {
        string try2 = s.substr(i, 2);
        if (tbl.find(try2) != tbl.end()) {
          ans += tbl[try2];
          i += 2;
        } else {
          ans += tbl[s.substr(i, 1)];
          i++;
        }
      } else {
        ans += tbl[s.substr(i, 1)];
        i++;
      }
    }

    return ans;
  }
};