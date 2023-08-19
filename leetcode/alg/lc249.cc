// leetcode 249
// Group Shifted Strings
// 字符串hash

#include <bits/stdc++.h>

using namespace std;

// 移位字符串分组
// 利用字符串hash来分组即可
// 在求解hash的时候，利用首字母的shift作为整个字符串的shift
class Solution {
public:    
    string hash(string& s) {
        int sft = s[0];
        string hashKey;
        for(int i=0; i<s.length(); i++) hashKey += (s[i] - sft + 26) % 26 + 'a';
        return hashKey;
    }
    
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string, vector<string>> m;
        
        for(string& s: strings) {
            string key = hash(s);
            m[key].push_back(s);
        }
        
        vector<vector<string>> ans;
        
        for(auto it=m.begin(); it!=m.end(); it++) ans.push_back(it->second);
        
        return ans;
    }
};