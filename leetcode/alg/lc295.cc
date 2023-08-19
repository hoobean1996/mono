// leetcode 295
// Median in Data Stream
// 数据流中的中位数
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // 最大堆存放 <= 中位数
    // 最小堆存放 > 中位数
    // [最大堆]  median [最小堆]
    // 当total是偶数的时候，往最大堆放，（考虑total = 0的时候，插入一个元素，由于最大堆 <= 中位数
    // 考虑只有一个元素插入进去的时候，要返回的是maxPq.top()
    priority_queue<int, vector<int>, greater<int> > minPq;
    priority_queue<int> maxPq;

    int total = 0;

    void insert(int num) {
        if (total % 2 == 0) {
            minPq.push(num);
            maxPq.push(minPq.top());
            minPq.pop();
        }
        else {
            maxPq.push(num);
            minPq.push(maxPq.top());
            maxPq.pop();
        }

        total++;
    }

    // 首先规定中位数的位置
    // 如果有奇数个数字
    // 那么中位数就是最大堆的最大值
    // 最大堆比最小堆多一个
    // 如果有偶数个数字
    // 那么中位数就是最大堆最小堆的平均数
    double getMedian() {
        if (total % 2 == 1) return (double)maxPq.top();
        else return (double)(maxPq.top() + minPq.top()) / 2;
    }
};