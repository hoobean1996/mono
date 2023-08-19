// leetcode 752
// open locks

// 我们有一个所，一共有4个轮盘，每个轮盘可以转为[0..9]
// 我们的锁是初始化为 0000
// 同时我们有一个死亡列表，如果我们把锁转成其中的任意一个状态，那么我们就会死亡
// 我们有一个目标状态，我们想知道需要多少步才能转到目标状态
// 如果不能的话，返回-1

// 这道题是给定了初始化状态和目标状态
// 我们可以利用双向BFS来优化我们的算法
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string s = "0000";
    string t;
    unordered_map<string, bool> deads;

    int openLock(vector<string>& deadends, string target) {
        t = target;
        
        // 如果初始状态和目标状态相同，那么肯定不需要任何操作
        if (s == t) return 0;
        
        // 记录一下死亡列表，用于排除不合法的状态
        for(int i=0; i<deadends.size(); i++) {
            deads[deadends[i]] = true;
            if (deadends[i] == s) return -1;
        }
        
        int ans = bfs();
        return ans;
    }
    
    int bfs() {
        // 给定的两个队列d1, d2
        // 分别是从起始状态开始的队列，目标状态的队列
        queue<string> d1;
        unordered_map<string, int> m1;
        d1.push(s);
        m1[s] = 0;

        queue<string> d2;
        unordered_map<string, int> m2;
        d2.push(t);
        m2[t] = 0;
        
        // 考虑任何一个队列为空的话，还没有找到，那肯定是不可达
        // 优先处理队列较小的那个
        // 因为每次处理一个元素，都会放入更多的元素到队列中
        while(!d1.empty() && !d2.empty()) {
            int t = -1;
            if (d1.size() <= d2.size()) t = solve(d1, m1, m2);
            else t = solve(d2, m2, m1);
            if (t != -1) return t;
        }
        
        return -1;
    }
    

    vector<int> steps = {1, 9};

    int solve(queue<string>& q, unordered_map<string, int>& m1, unordered_map<string, int>& m2) {
        // 从需要处理的队列中取出一个
        string u = q.front(); q.pop();
        
        int dist = m1[u];
        
        for(int i=0; i<4; i++) {
            // 可以 +1
            // 可以 -1
            for(const int step: steps) {
                int next = ((u[i] - '0') + step) % 10;
                string t = u;
                t[i] = (char)(next + '0');
                // 排除死亡转盘
                if (deads.count(t) > 0) continue;
                // 如果已经访问过
                if (m1.count(t) > 0) continue;
                // 如果已经找到
                if (m2.count(t) > 0) return dist + 1 + m2[t];
                else {
                    q.push(t);
                    m1[t] = dist + 1;
                }
            }
        }
        return -1;
    }
};