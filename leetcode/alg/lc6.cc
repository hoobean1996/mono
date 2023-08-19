// leetcode 6
// ZigZag Conversion

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  string convert(string s, int numRows) {
    if (numRows == 1)
      return s;

    string ans;
    int n = s.length();
    int cycleLen = 2 * numRows - 2;

    for (int i = 0; i < numRows; i++) {
      for (int j = 0; j + i < n; j += cycleLen) {
        ans += s[j + i];
        if (i != 0 && i != numRows - 1 && j + cycleLen - i < n)
          ans += s[j + cycleLen - i];
      }
    }

    return ans;
  }
};