// leetcode 763
// Partition Labels

// 给定一串字符串s，我们希望把该字符串划分为多个部分
// 对于每个字符串，它只能出现在其中的某个部分.
// 同时我们希望划分的尽可能多的部分

// 比如ababcbacadefegdehijhklij
// 划分的结果是 "ababcbaca", "defegde", "hijhklij"
// 首先统计每个字符串出现的最后的位置

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> lastPos(26, 0);
        for(int i=0; i<s.length(); i++) lastPos[s[i] - 'a'] = i;


        // [l..r] 代表当前的划分区间
        // 对于任意的s[i],我们必须把 i..lastPos[s[i]]之间的所有字符划分进去
        // r = lastPos[s[i]]
        // 然后处理[i+1..r-1]之间的所有字符，如何任何字符的末尾位置超过当前的r
        // 那么r就要继续更新
        int l = 0;
        int r = 0;
        vector<int> ans;

        for(int i=0; i<s.length(); i++) {
            // 如果该字符出现的很远的地方，那么也需要包含进去，所以
            // r 永远是在当前的r 和 lastPos[s[i] - 'a] 之间选择
            r = max(r, lastPos[s[i] - 'a']);

            // 如果当前的i == r的话，意味着划分完成了，可以进入下一个划分了， l = r+1
            if (i == r) {
                ans.push_back(i - l + 1);
                l = r + 1;
            }
        }

        return ans;
    }
};