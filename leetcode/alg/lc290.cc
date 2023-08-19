// leetcode 290
// Word Pattern 

#include <bits/stdc++.h>

using namespace std;

// 给定两个字符串，问是不是同一个pattern
// 存在唯一的映射c -> string, string->c
// 相比Word Pattern II来说，这道题由于已经把字符串s分割完成
// 所以我们只需对比即可
// 1. 比较长度是否相同

class Solution {
public:
    vector<string> split(string s) {
        vector<string> ans;
        int lastIndex = 0;
        int index;

        while ((index = s.find(" ", lastIndex)) != string::npos) {
            ans.push_back(s.substr(lastIndex, index - lastIndex));
            lastIndex = index + 1;
        }

        if (lastIndex != s.length()) {
            ans.push_back(s.substr(lastIndex, s.length() - lastIndex));
        }

        return ans;
    }
    
    // 由于单词本身已经按照空格进行划分
    // 所以我们直接调用split函数得到单词数组
    // 1. 两个数组必须有相同的长度
    // 2. 我们把每个单词/字母出现的第一次和他的坐标进行绑定，
    // 其他时间，如果已经绑定过的字符/字母 我们直接判断他们两个绑定的坐标是否相同
    bool wordPattern(string pattern, string s) {
        unordered_map<string, int> m;

        vector<string> words = split(s);
        if (words.size() != pattern.length()) return false;

        for (int i = 0; i < words.size(); i++) {
            string c = to_string(pattern[i]);
            string w = words[i];

            // 同时转换为字符串，并把模式字符的下标
            // 和字符串的下标都存起来
            if (m.count(c) == 0) m[c] = i;
            if (m.count(w) == 0) m[w] = i;
            
            if (m[c] != m[w]) return false;
        }

        return true;
    }
};