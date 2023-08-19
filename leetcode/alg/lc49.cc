// leetcode 49
// Group Anagrams

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:   
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        
        if (strs.size() == 0) return ans;
        
        unordered_map<string, vector<string>> m;
        
        for(int i=0; i<strs.size(); i++) {
            string key = strs[i];
            sort(key.begin(), key.end());
            m[key].push_back(strs[i]);
        }
        
        for(auto it = m.begin(); it != m.end(); it++) {
            ans.push_back(it->second);
        }
        
        return ans;
    }
};