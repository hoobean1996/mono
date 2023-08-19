// leetcode 248
// Strobogrammatic Number III

// 如果中心对称数的长度是偶数， 则可以 01689
// 如果中心对称数的长度是奇数， 则可以 018

// 所以我们可以从“” 开始 来处理所有的偶数长度的情况
// 也可以从 018 开始 来处理所有的奇数长度的情况
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int ans;
    string _low;
    string _high;

    void dfs(string cur) {
        // 在有效的范围内
        if (cur.size() >= _low.size() && cur.size() <= _high.size()) {
            if (
                !(
                    // 大于最大值
                    (cur.size() == _high.size() && cur > _high) ||
                    // 小于最小值
                    (cur.size() == _low.size() && cur < _low) ||
                    // 首位是0的情况
                    (cur.size() >= 2 && cur[0] == '0')
                )
            ) ans ++;
        }

        if (cur.size() + 2 > _high.size()) return;

        vector<string> table = {"0", "1", "8", "6",  "9"};
        vector<string> rtable = {"0", "1", "8", "9", "6"};

        for(int i=0; i<table.size(); i++) dfs(table[i] + cur + rtable[i]);
    }

    int strobogrammaticInRange(string low, string high) {
        _low = low;
        _high = high;

        // 如果是偶数的话，相当于""
        dfs("");
        // 如果是奇数的话，可以018
        dfs("1");
        dfs("0");
        dfs("8");

        return ans;
    }
};