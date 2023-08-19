// leetcode 252
// Meeting Rooms

// 给定一个数组，每个数组元素是一个区间，代表一个会议的开始时间和结束时间
// 我们想知道一个人是否能够参加所有的会议
// 这个问题其实就是相当于问所有的区间是否有重叠
// 所以我们按照开始时间排序
// 然后从第二个元素开始和prev的元素做对比，如果当前元素的开始时间比prev的结束时间还早，那么肯定就是不能参加所有的会议
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        if (intervals.size() == 0) return true;
        
        sort(intervals.begin(), intervals.end(), [](const vector<int>& i1, const vector<int>& i2){
            return i1[0] < i2[0]; 
        });
        
        
        vector<int> prev = intervals[0];
        
        for(int i=1; i<intervals.size(); i++) {
            if (intervals[i][0] < prev[1]) return false;
            else prev = intervals[i];
        }
        
        return true;
    }
};