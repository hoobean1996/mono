// leetcode 131
// Palindrome Partitioning

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int n;
    vector<vector<string>> ans;
    string s;
    
    bool valid(string s) {
        int l = 0;
        int r = s.length() - 1;
        
        while(l <= r) {
            if (s[l++] != s[r--]) return false;
        }

        return true;
    }
    
    // cur 起始位置
    // path 当前的字串
    void backtrack(int cur, vector<string>& path, string s) {
        if (cur == n) {
            ans.push_back(path);
            return;
        }
        // 枚举所有的字串
        for(int l=1; l<=(n-cur); l++){
            string part = s.substr(cur, l);
            // 如果是有效的回文串，放入到答案中
            if (valid(part)) {
                path.push_back(part);
                backtrack(cur+l, path, s);
                path.pop_back();
            }
        }
    }
    // 这道题回溯即可，枚举所有可能的字串
    // 将一个字符串划分成多个回文串
    vector<vector<string>> partition(string s) {
        n = s.length();
        ans = vector<vector<string>>();
        vector<string> path = vector<string>();
        backtrack(0, path, s);
        return ans;
    }
};