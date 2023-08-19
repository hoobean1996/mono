// leetcode 451
// Sort Characters By Frequency
// 给定一个字符串，我们需要重新排列该字符串，使得它按照每个字符的频率排序
// 首先利用一个hashmap来记录每个字符出现的频率
// 然后构造一个pair<int, char>的数组，然后利用频率排序即可
// 最后顺序输出
// 复杂度 O(nlogn)


#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        map<char, int> m;
        for(int i=0; i<s.length(); i++) {
            if ((m.find(s[i])) != m.end()) m[s[i]] += 1;
            else m[s[i]] = 1;
        }
        
        vector<pair<int, char>> v;
        
        map<char, int>::iterator it;
        for(it = m.begin(); it != m.end(); it++) {
            v.push_back(make_pair(it->second, it->first));
        }
        
        sort(v.begin(), v.end(), [](const pair<int, int>& a, const pair<int, int>& b){
            return a.first > b.first;
        });
        string res;
        for(int i=0; i<v.size(); i++) {
            for(int j=0; j<v[i].first; j++) res += v[i].second;
        }
        
        return res;
    }
};
