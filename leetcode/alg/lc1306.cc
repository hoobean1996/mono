// leetcode 1306
// Jump Game iii 

// Jump Game III 是位移的方式变为可以 i + nums[i] / i - nums[i]
// 相当于有两个方向的移动
// 同时需要判断我们是否可以移动到任意一个值为0的格子
// 可以利用BFS求解
// 去重的方式可以用额外的数组，也可以用本身的信息，由于所有的元素都是>=0的，
// 所以如果已经走过一个位置的话，我们是可以直接变为负数，从而来去重的
// 如果没有这个条件的话，我们就只能用额外的数组进行去重
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        
        queue<int> q;
        q.push(start);
        
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            
            // 移动到值为0的格子，直接返回true
            if (arr[node] == 0) return true;
            
            // 否则的话，
            // 利用将arr[node]变为负数来判重
            // 所以条件为 arr[node] > 0
            if (arr[node] > 0) {
                if (node + arr[node] < n) q.push(node + arr[node]);
                if (node - arr[node] >= 0) q.push(node - arr[node]);
                arr[node] = -arr[node];
            }
        }
        
        return false;
    }
};