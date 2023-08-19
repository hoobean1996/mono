// leetcode 140
// Work Break II

#include <bits/stdc++.h>

using namespace std;

// 将一个字符串拆分成字典中的不同单词的方案
// 利用一个Set记录所有可能的字符串
// 然后遍历所有可能的子串，对于出现Set中的字符串，我们递归调用即可
class Solution {
public:
    unordered_map<string, vector<string>> _cache;
    unordered_set<string> _st;
    
    vector<string> backtrack(string s) {
        if (s.length() == 0) return {""};

        if (_cache.count(s)) return _cache[s];
        
        vector<string> ans;
        
        for(int i=0; i<s.length(); i++) {
            // 切割掉一部分，如果该字串在整个集合中出现，那么证明可以继续下去
            string sub = s.substr(0, i+1);
            if (_st.count(sub)) {
                vector<string> subAns = backtrack(s.substr(i+1));
                for(const string& t: subAns) {
                    ans.push_back(sub + (t == "" ? "" : " ") + t);
                }
            } 
        }
        _cache[s] = ans;
        return ans;
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        _st = unordered_set<string>(begin(wordDict), end(wordDict));                
        
        return backtrack(s);
    }
};