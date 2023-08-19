// leetcode 759
// Employee Free Time

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>>& schedule) {
        vector<Interval> ans;


        map<int, int> m;
        for(const auto& s: schedule) {
            for(const auto& i: s) {
                ++ m[i.start];
                -- m[i.end];
            }
        }

        int sum = 0;
        for(const auto& p: m) {
            sum += p.second;
            if (sum == 0) ans.push_back(Interval(p.first, -1));
            else if (!ans.empty() && ans.back().end == -1) ans.back().end = p.first;
        }

        if (!ans.empty()) ans.pop_back();
        return ans;
    }
};