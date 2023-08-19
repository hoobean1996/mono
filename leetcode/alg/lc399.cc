// leetcode 399
// Evaluate Division
// 除法运算
// 这道题可以利用带权并查集做
// 也可以用图论做
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // 用map实现的并查集
    unordered_map<int, pair<int, double>> father;
    
    // find 函数
    int find(int x) {
        
        if (x != father[x].first) {
            int t = father[x].first;
            
            father[x].first = find(father[x].first);
            father[x].second *= father[t].second;
        }
        
        return father[x].first;
    }
    
    void un(int e1, int e2, double result) {
        int f1 = find(e1);
        int f2 = find(e2);
        if (f1 != f2) {
            father[f2].first = f1;
            father[f2].second = father[e1].second * result / father[e2].second;
        }
    }
    
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        vector<double> ans;
        
        unordered_map<string, int> labelToID;
        
        int id = 1;
        
        for(int i=0; i<equations.size(); i++) {
            string x = equations[i][0];
            string y = equations[i][1];
            
            if (labelToID[x] == 0) {
                labelToID[x] = id;
                father[id].first = id;
                father[id].second = 1;
                id ++;
            }
            
            if (labelToID[y] == 0) {
                labelToID[y] = id;
                father[id].first = id;
                father[id].second = 1;
                id ++;
            }
            
            
            int e1 = labelToID[x];
            
            int e2 = labelToID[y];
            
            un(e1, e2, values[i]);
        }
        
        
        for(int i=0; i<queries.size(); i++) {
            string x = queries[i][0];
            string y = queries[i][1];
            
            
            if (labelToID[x] == 0 || labelToID[y] == 0) {
                ans.push_back(-1.0);
                continue;
            }
            
            int e1 = labelToID[x];
            int e2 = labelToID[y];
            
            
            int f1 = find(e1);
            int f2 = find(e2);

            if (f1 != f2) ans.push_back(-1.0);
            else {
                double t1 = father[e1].second;
                double t2 = father[e2].second;
                
                ans.push_back(t2 / t1);
            }
        }
        
        return ans;
    }
};