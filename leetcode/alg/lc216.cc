// leetcode 216
// Combination Sum III

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> _ans;
    int _target;
    int _k;
    
    void backtrack(int start, int sum,  vector<int>& path) {
        if (path.size() == _k && sum == _target) {
            _ans.push_back(path);
            return;
        } 
        
        for(int i=start; i<=9; i++) {
            if (sum + start <= _target) {
                path.push_back(i);
                backtrack(i + 1, sum + i, path);
                path.pop_back();
            }
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        _target = n;
        _k = k;
        
        vector<int> path;
        backtrack(1, 0, path);
        
        return _ans;
    }
};