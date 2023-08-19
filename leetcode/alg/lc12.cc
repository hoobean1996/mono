// leetcode 12
// Integer to Roman

// 数字转换为罗马字符
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        vector<pair<int,string>> tbl {
            {1, "I"},
            {4, "IV"},
            {5, "V"},
            {9, "IX"},
            {10, "X"},
            {40, "XL"},
            {50, "L"},
            {90, "XC"},
            {100, "C"},
            {400, "CD"},
            {500, "D"},
            {900, "CM"},
            {1000, "M"}
        };
        
        string ans;
        
        while (num) {
            int k = tbl.size() - 1;
            while(num < tbl[k].first) k--;
            // 找到num的位置
            // 然后将当前的数减少，
            if(num >= tbl[k].first) {
                ans += tbl[k].second;
                num -= tbl[k].first;
                k = tbl.size() - 1;
            }
        }
        
        return ans;
    }
};