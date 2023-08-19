// leetcode 547
// Number of Provinces

// 一共有n个城市，有些城市之间是相连的，如果两个城市是相连的，A<->B, B<->C, 那么A<->C
// 一组相连的城市就是一个province，我们想知道一共有多少个province

#include <bits/stdc++.h>
using namespace std;

// 使用并查集来解决
int fa[205];

int find(int x) {
    if(x != fa[x]) fa[x] = find(fa[x]);
    return fa[x];
}

bool U(int x, int y) {
    int a = find(x);
    int b = find(y);
    if (a != b) {
        fa[b] = a;
        return true;
    }
    return false;
}


class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        
        int ans = n;
        for(int i=0; i<n; i++) fa[i] = i;
        
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                // 如果是相连的，同时也是可以merge一次的情况下，ans -- 
                if (isConnected[i][j] && U(i, j)) ans --;
            }
        }
        
        return ans;
    }
};