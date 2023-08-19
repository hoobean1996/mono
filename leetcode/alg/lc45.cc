// leetcode 45
// Jump Game ii


// 跳跃游戏 II
// 初始化的时候在第一个位置，每次可以跳跃的格子不超过格子的值
// 求解最少的跳跃次数
#include <bits/stdc++.h>

using namespace std;

// Jump Game ii 需要求的到达最后位置的最小次数
int jump(vector<int>& nums) {
    int n = nums.size();
    if (n == 1) return 0;

    // 设 last 是当前已经到达的位置，初始化为 -1
    int last = -1;

    // 设 cur 是当前可以到达的位置，初始化就是第一个位置的情况
    int cur = nums[0] + 0;

    // 设 count 是当前走的步数
    int count = 0;

    for(int i=0; i<n; i++) {
        // 如果当前的 i > last 
        // 证明我们已经来到了更远的位置，
        // 需要更新last 和 步数
        if (i > last) {
            last = cur;
            count ++;
        } 
        
        // 如果当前的已经到达的距离 last >= n-1，证明我们已经到达最后一个位置了
        if (last >= n-1) return count;

        // 当前可以到达的位置应该是上一个cur, 和现在的位置的新的可达距离的最大值
        cur = max(cur, nums[i] + i);
    }

    return count;
}