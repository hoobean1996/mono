// leetcode 435
// Non-Overlapping Intervals

// 给定一组区间数组，我们想知道为了让所有的区间都不想交，我们需要移除的区间个数是多少
// 一样的，维护一个prev指针，判断当前区间和上一个区间的关系，如果相交，就移除一个

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.size() == 0) return 0;
    
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });
        
        int ans = 0;
        int prev = 0;
        
        for(int i=1; i<intervals.size(); i++) {  
            if (intervals[i][0] < intervals[prev][1]) ans ++;
            else prev = i;
        }
        
        return ans;
    }
};