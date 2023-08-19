// leetcode 39
// Combination Sum

// 给定一个数组，里面都是互不相同的元素。
// 我们想知道里面从中选出一些元素来构成一个集合，是的集合的元素和为指定的值的方案有哪些

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> ans;
    vector<int> cs;
    
    void dfs(int target, vector<int>& t) {
        if (target == 0) {
            vector<int> copyt = t;
            sort(copyt.begin(), copyt.end());
            ans.push_back(copyt);
            return;
        }
        
        for(int i=0; i<cs.size(); i++) {
            if (target >= cs[i]) {
                t.push_back(cs[i]);
                dfs(target-cs[i], t);
                t.pop_back();
            }
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        cs = candidates;
        
        vector<int> temp;
        dfs(target, temp);
        
        if (ans.size() == 0 || ans.size() == 1) return ans; 
        
        
        sort(ans.begin(), ans.end());
        
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        
        return ans;
    }
};