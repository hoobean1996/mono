// leetcode 791
// Custom Sort String 

// 给定两个字符串，一个是order， 一个是字符串s
// 在order中的所有字符都是唯一的，并且按照某种特别的顺序排列的
// 我们希望重排字符串s使得它满足和order一样的顺序
// 首先我们可以统计字符出现的频率信息，然后基于order来输出即可
#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    string customSortString(string order, string s) {
        // 首先遍历字符串s，统计频率
        unordered_map<char,int> m;
        for(int i=0; i<s.length(); i++) m[s[i]]++;
        
        string ans;
        
        // 遍历顺序，确保输出的顺序是对的
        // 如果s中没有该字符，则忽略
        // 如果有该字符，输出k此
        for(int i=0; i<order.length(); i++) {
            if (m.count(order[i]) == 0) continue;
            else {
                while(m[order[i]]-- > 0) ans += order[i];
            }
        }
        
        // 其他剩余的字符，随意输出即可
        for(auto it: m) while(it.second-- > 0) ans += it.first;
        return ans;
    }
};