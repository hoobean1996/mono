// leetcode 207
// Course Schedule
// 课程安排 I
// 只是需要判断是否可以安排
// 这个题是用来检测图中是否有环的

// 需要特别注意的是边界条件
// 1. 在统计入度的时候，遇到了循环边
// 2. 不存在入度为0度节点
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);

        for(vector<int>& edge: prerequisites) {
            if (edge[0] == edge[1]) return false;
            indegree[edge[0]] ++;
        }
        
        queue<int> q;
        
        for(int i=0; i<indegree.size(); i++) {
            if (indegree[i] == 0) q.push(i);
        }
        
        if (q.empty()) return false;
        
        int ans = 0;
        
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            ans++;
            
            for(vector<int>& edge: prerequisites) {
                if (edge[1] == u) {
                    if (--indegree[edge[0]] == 0) q.push(edge[0]);
                }
            }
            
            if (ans > numCourses) return false;
        }
        
        return ans == numCourses;
    }
};