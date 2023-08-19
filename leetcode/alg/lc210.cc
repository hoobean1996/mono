// leetcode 210
// Course Schedule II


// 课程安排 II
// 相比于Course Schedule I
// 我们需要给出方案
// 也是需要按照拓扑排序的思路, 在弹出队列的时候记录方案即可
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> findegreeOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        // indegree
        vector<int> indegree(numCourses, 0);

        for (vector<int> &edge : prerequisites) {   
            // 循环节点，直接返回即可
            if (edge[0] == edge[1]) return {};
            indegree[edge[0]]++;
        }

        queue<int> q;
        // 首先把入度为0的节点，加入到队列中
        for (int i = 0; i < indegree.size(); i++) {
            if (indegree[i] == 0) q.push(i);
        }

        if (q.size() == 0) return {};

        vector<int> ans;

        int processed = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            processed++;
            ans.push_back(u);
            for (vector<int> &edge : prerequisites) {
                if (edge[1] == u) {
                    if (--indegree[edge[0]] == 0) q.push(edge[0]);
                }
            }
            
            // 如果已经处理的数量比实际的课程多，那么证明有循环
            if (processed > numCourses) return {};
        }

        return processed == numCourses ? ans : vector<int>();
    }
};