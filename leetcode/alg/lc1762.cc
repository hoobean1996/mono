// leetcode 1762
// Buildings with an Ocean view

// 有一组建筑靠海，我们希望找到那些能够看到海的海景房是哪些
// 就是用单调栈即可，维护一个单调递减的栈
// 但是如果我们从右到左进行遍历，并维护一个最大值的话，可以优化掉栈的使用
// 因为每个海景房一定是从右往左的最大值，（如果有一个比它高的话，那么肯定不是海景房）
// 所以我们维护一个当前遍历的最大值
// 如果当前的高度比最大值大，那么肯定是海景房，加入到答案，并更新最高高度
#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        // 优化过后的解法，其实可以考虑从右到左
        // 如果当前的最大值小于当前的建筑高度，那它肯定是海景房
        int n = heights.size();
        vector<int> ans;

        int maxHeight = INT_MIN;

        for(int i=n-1; i>=0; i--) {
            if (heights[i] >= maxHeight) {
                ans.push_back(i);
                maxHeight = heights[i];
            }
        }

        // 需要反转，由于返回的顺序是从左到右的
        reverse(heights.begin(), heights.end());
        return ans;
    }
};

