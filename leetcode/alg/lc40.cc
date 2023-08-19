// leetcode 40 
// Combination Sum II

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> ans;
    
    void dfs(int target, vector<int>& t, unordered_map<int, int> candidates) {
        if (target == 0) {
            vector<int> copyt = t;
            sort(copyt.begin(), copyt.end());
            ans.push_back(copyt);
            return ;
        } 
        
        auto it = candidates.begin();
        
        for(auto it=candidates.begin(); it != candidates.end(); it++) {
            if (it->second > 0 && target >= it->first) {
                t.push_back(it->first);
                it->second--;
                dfs(target - it->first, t, candidates);
                it->second++;
                t.pop_back();
            }
        }
        
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        unordered_map<int, int> counter;
        for(int i=0; i<candidates.size(); i++) {
            if (counter.find(candidates[i]) != counter.end()) counter[candidates[i]]++;
            else counter[candidates[i]] = 1;
        }
   
        vector<int> temp;
        
        dfs(target, temp, counter);
        
        sort(ans.begin(), ans.end());
        if (ans.size() == 1 || ans.size() == 0) return ans;
        
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        
        return ans;
    }
};