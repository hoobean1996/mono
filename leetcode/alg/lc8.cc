// leetcode 8
// String to Integer

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int myAtoi(string s) {
    int sign = 0;
    string nums = "";

    for (int i = 0; i < s.length(); i++) {
      // 如果当前符号、数字都没有，遇到空格都跳过
      if (sign == 0 && nums == "" && s[i] == ' ') {
        continue;
      };

      // 如果符号还没有，遇到了+，则初始化符号
      if ((s[i] == '+' || s[i] == '-') && sign == 0) {
        sign = s[i] == '+' ? 1 : -1;
        continue;
      }

      // 一旦遇到数字，如果符号没有初始化的话，记得初始化符号，同时记录nums
      if (s[i] >= '0' && s[i] <= '9') {
        if (sign == 0) {
          sign = 1;
        }
        nums += s[i];
        continue;
      }

      // 其他情况都可以break
      break;
    }

    // 去除头部的无效的0
    int validI = 0;

    while (nums[validI] == '0')
      validI++;

    long long ret = 0;
    // 从最后一位开始累加
    for (int i = validI; i < nums.length(); i++) {
      ret = ret * 10 + (nums[i] - '0');
      if (sign == 1 && ret >= INT_MAX)
        return INT_MAX;
      if (sign == -1 && ret >= (long long)INT_MAX + 1)
        return INT_MIN;
    }

    return ret * sign;
  }
};