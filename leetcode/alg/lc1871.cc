// leetcode 1871
// Jump Game 4

// Jump Game的进阶版本
// 每次可以移动minJump - maxJump之间的任何一个步子
// 我们希望知道能否到达最后一个位置
// 这道题确实是用BFS，但是如果不剪枝的话 是无法通过的
// 首先把第一个位置放入队列，然后我们不断的从队列中取出当前的位置
// 通过考虑移动minJump - maxJump，来得到下一次可能移动的位置
// 画图以后就能看见，两个位置是可能有很大的相叠的部分的。所以我们最好维护一个当前最远的距离来进行剪枝
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.length();
        queue<int> q;
        q.push(0);
        
        vector<bool> vis = vector<bool>(n+1, false);
        vis[0] = true;

        // farthest 代表当前移动的最远距离
        int farthest = 0;
        
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            vis[u] = true;            
            
            if (u == n-1) return true;
            
            // 如果不进行剪枝的话，那么我们就之间进行处理
            // u + minJump .. u + maxJump
            // 但是这样会有很多重复的项
            // 所以我们维护一个最远的进行剪枝处理
            int start = max(u + minJump, farthest + 1);
            int end = min(u + maxJump, n - 1);

            for(int j=start; j<=end; j++) {
                if (j >= 0 && j < n && s[j] == '0' && !vis[j]) {
                    q.push(j); 
                }
            }
            farthest = u + maxJump;
        }
        
        return false;
    }
};