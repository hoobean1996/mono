// leetcode 415
// Add Strings

// 给定两个字符串，我们想得到他们数值相加以后的字符串结果
// 用三目运算符简化运算
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        string ans;
        int c = 0;
        int i = num1.length() - 1;
        int j = num2.length() - 1;
        
        while (i >= 0 || j >= 0) {
            int x = i >= 0 ? num1[i] - '0' : 0;
            int y = j >= 0 ? num2[j] - '0' : 0;
            int val = (x + y + c) % 10;
            c = (x + y + c) / 10;
            ans += to_string(val);
            i--;
            j--;
        }

        if (c > 0) ans += to_string(c);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};