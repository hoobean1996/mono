// leetcode 815
// Bus Routes
// 给定几个公交车路线，每个公交车路线都是一个数组，其中包含一组站点
// 公交车在一条路线上循环开车
// 我们希望给定一个出发站 和 终点站，想要知道需要乘坐多少条公交车线路才能到达
// 首先我们有的一组routes，相当于一组线路
// 我们遍历所有的站点，维护一个 stop -> route的关系
// 利用bfs的思路
// 一开始把开始站点对应的线路放进队列
// 然后每次从队列中取出一个线路，把它的所有站点处理一下, 如果对应的线路有终点站的话，
// 那么就结束，否则的话，把对应的站点的线路添加到队列中
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target) return 0;

        int n = routes.size();
        vector<vector<int>> graph(1e5 + 5);

        // 存放站台 -> 线路的信息
        for(int i=0; i<routes.size(); i++) {
            for(int j=0; j<routes[i].size(); j++) {
                graph[routes[i][j]].push_back(i);
            }
        }

        // 把开始站台的所有线路都放进去
        queue<int> q;
        for(const int n: graph[source]) q.push(n);

        int ans = 1;
        set<int> st;

        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                // 当前访问的线路
                int route = q.front(); q.pop();

                // 如果这条线路没有访问过
                if (st.count(route)) continue;

                // 遍历当前线路的所有站台
                for(const int stop: routes[route]) {
                    // 如果有终点站，那么接受
                    if (stop == target) return ans;
                    // 否则的话，把该站台的所有线路放进去
                    for(const int y: graph[stop]) q.push(y);
                }

                st.insert(route);
            }
            ans ++;
        }

        return -1;
    }
};